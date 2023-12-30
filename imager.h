//
// Created by lavandejoey on 29/09/23.
//

#ifndef IMAGER_TMP_IMAGER_H
#define IMAGER_TMP_IMAGER_H

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>

#include <QMessageBox>
#include <QPalette>

#include <QtWidgets>

#include <QMainWindow>
#include <qcameraimagecapture.h>
#include "settings.h"
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui { class imager; }
QT_END_NAMESPACE

class imager : public QMainWindow {
Q_OBJECT

public:
    explicit imager(QWidget *parent = nullptr);

    ~imager() override;

private:
    Ui::imager *mUi;
    QScopedPointer<QCamera> mCamera;
    QScopedPointer<QCameraImageCapture> mImageCapture;
//    QScopedPointer<QMediaRecorder> mMediaRecorder;

    settings mqdialogSettings;

signals:

private slots:

    // Camera slots:
    void startCamera();
    void stopCamera();

    void configSettings();

    // Photography and saving:
    void captureImage();

    void updateFocalLength(int sliderValue);

};


#endif //IMAGER_TMP_IMAGER_H
