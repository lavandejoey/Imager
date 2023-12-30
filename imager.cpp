//
// Created by lavandejoey on 29/09/23.
//

#include "imager.h"
#include "ui_imager.h"

Q_DECLARE_METATYPE(QCameraInfo)

imager::imager(QWidget *parent) :
        QMainWindow(parent), mqdialogSettings(this), mUi(new Ui::imager) {
    mUi->setupUi(this);

    // Hide "tabVideo" in "tabWidget"
    int _tabVideoIndex = mUi->tabWidget->indexOf(mUi->tabVideo);
    mUi->tabWidget->removeTab(_tabVideoIndex);

    // Set viewfinder size by resolution
    QString resolution = QString::fromStdString(mqdialogSettings.mSaveResolution);
    QStringList resolutionList = resolution.split("x");
    int width = resolutionList.at(0).toInt() / 2;
    int height = resolutionList.at(1).toInt() / 2;
    mUi->viewfinderFrame->setFixedSize(width, height);

    //Start camera:
    connect(mUi->actionStartCamera, &QAction::triggered, this, &imager::startCamera);
    //Stop camera:
    connect(mUi->actionStopCamera, &QAction::triggered, this, &imager::stopCamera);
    //Exit:
    connect(mUi->actionExit, &QAction::triggered, this, &imager::close);

    //Camera devices:
    QActionGroup *videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);
    const QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();
    for (const QCameraInfo &cameraInfo: availableCameras) {
        QAction *videoDeviceAction = new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);
        mUi->menuDevices->addAction(videoDeviceAction);
    }
    connect(videoDevicesGroup, &QActionGroup::triggered, this, [this](QAction *action) {
        const QCameraInfo cameraInfo = qvariant_cast<QCameraInfo>(action->data());
        if (cameraInfo.isNull()) {
            QMessageBox::warning(this, tr("Camera"), tr("Failed to open the camera"));
        } else {
            mUi->statusbar->showMessage(tr("Camera changed to %1").arg(cameraInfo.description()));
        }
    });
    startCamera();

    // Capture pushButtonCapture
    connect(mUi->pushButtonCapture, &QPushButton::clicked, this, &imager::captureImage);
    // Connect the slider to a slot or lambda function
    connect(mUi->horizontalSliderPhoto, &QSlider::valueChanged, this, &imager::updateFocalLength);
    connect(mUi->horizontalSliderVideo, &QSlider::valueChanged, this, &imager::updateFocalLength);

    // Recording buttons
//    connect(mUi->pushButtonRecord, &QPushButton::clicked, this, &imager::startRecording);
//    connect(mUi->pushButtonPause, &QPushButton::clicked, this, &imager::pauseRecording);
//    connect(mUi->pushButtonStop, &QPushButton::clicked, this, &imager::stopRecording);
//    connect(mUi->checkBoxMute, &QCheckBox::toggled, this, &imager::toggleMutedRecording);
//    mMediaRecorder.reset(new QMediaRecorder(mCamera.data()));
//    connect(mMediaRecorder.data(), &QMediaRecorder::durationChanged, this, &imager::updateRecordTime);

    // Disable pause and stop
    mUi->pushButtonPause->setEnabled(false);
    mUi->pushButtonStop->setEnabled(false);

    //Settings:
    connect(mUi->actionPreference, &QAction::triggered, this, &imager::configSettings);
    //About:
    connect(mUi->actionAbout, &QAction::triggered, this, [this]() {
        about qdialogAbout(this);
        qdialogAbout.show();
        qdialogAbout.exec();
    });
}

imager::~imager() {
    delete mUi;
}

void imager::startCamera() {
    mUi->statusbar->showMessage(tr("Camera started"));
    mCamera.reset(new QCamera(QCameraInfo::defaultCamera()));
    // Set zoom slider range and step
    mUi->horizontalSliderPhoto->setRange(static_cast<int>(mCamera->focus()->opticalZoom()),
                                         static_cast<int>(fmax(mCamera->focus()->maximumDigitalZoom(),
                                                               mCamera->focus()->maximumOpticalZoom())));
    // Set the viewfinder
    mCamera->setViewfinder(mUi->viewfinderFrame);
    mCamera->start();
}

void imager::stopCamera() {
    mUi->statusbar->showMessage(tr("Camera stopped"));
    mCamera.reset();
}


void imager::configSettings() {
    mqdialogSettings.show();
    mqdialogSettings.exec();
    // resize the viewfinderFrame by resolution
    QString resolution = QString::fromStdString(mqdialogSettings.mSaveResolution);
    QStringList resolutionList = resolution.split("x");
    int width = resolutionList.at(0).toInt() / 2;
    int height = resolutionList.at(1).toInt() / 2;
    mUi->viewfinderFrame->setFixedSize(width, height);
}

void imager::captureImage() {
    // capture from viewfinder and save to file
    mImageCapture.reset(new QCameraImageCapture(mCamera.data()));
    mImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    QString savePath = QString::fromStdString(mqdialogSettings.mSavePath);
    QString saveFormat = QString::fromStdString(mqdialogSettings.mSaveFormat);
    QString saveFileName = savePath + "/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + "." + saveFormat;
    mImageCapture->capture(saveFileName);
    mUi->statusbar->showMessage(tr("Saved to %1").arg(saveFileName));
}


// Slot or lambda function to update the camera's focal length or zoom
void imager::updateFocalLength(int sliderValue) {
    // Assuming 'camera' is your QCamera instance
    if (mCamera->isAvailable()) {
        // Set the camera zoom
        mCamera->focus()->zoomTo(1, (qreal) sliderValue);
        // Update the camera settings as needed
        mCamera->searchAndLock();
        // You may need to set other camera parameters like exposure, focus mode, etc.
        mCamera->unlock();
    }
}


