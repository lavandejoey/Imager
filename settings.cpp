//
// Created by lavandejoey on 29/09/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_settings.h" resolved

#include "settings.h"
#include "ui_settings.h"


settings::settings(QWidget *parent) :
        QDialog(parent), mUi(new Ui::settings) {
    // setup ui
    mUi->setupUi(this);

    // Hide "tabVideo" in "tabWidget"
    int _tabVideoIndex = mUi->tabWidget->indexOf(mUi->tabVideo);
    mUi->tabWidget->removeTab(_tabVideoIndex);

    // comboBoxFormat, comboBoxResolution select items
    mUi->comboBoxFormat->addItems(QStringList() << "jpg" << "png");
    mUi->comboBoxResolution->addItems(QStringList() << "1920x1080" << "1280x720" << "640x480");
    // config settings r/creates
    configSettings();
    // link selectSavePath with toolButtonSavePath
    connect(mUi->toolButtonSavePath, &QToolButton::clicked, this, &settings::selectSavePath);

}

settings::~settings() {
    delete mUi;
}

void settings::configSettings() {
    // Check if config file exists
    bool isConfigFileExist = QFile::exists(QString::fromStdString(mConfigPath));
    // Read and overwrite params if config file exists
    if (isConfigFileExist) {
        QSettings settings(QString::fromStdString(mConfigPath), QSettings::IniFormat);
        mSavePath = settings.value("savePath").toString().toStdString();
        mUi->lineEditSavePath->setText(QString::fromStdString(mSavePath));
        mSaveFormat = settings.value("saveFormat").toString().toStdString();
        mUi->comboBoxFormat->setCurrentText(QString::fromStdString(mSaveFormat));
        mSaveResolution = settings.value("saveResolution").toString().toStdString();
        mUi->comboBoxResolution->setCurrentText(QString::fromStdString(mSaveResolution));
    } else {// Create config file and set params by default
        QSettings settings(QString::fromStdString(mConfigPath), QSettings::IniFormat);
        settings.setValue("savePath", QString::fromStdString(mSavePath));
        mUi->lineEditSavePath->setText(QString::fromStdString(mSavePath));
        settings.setValue("saveFormat", QString::fromStdString(mSaveFormat));
        mUi->comboBoxFormat->setCurrentText(QString::fromStdString(mSaveFormat));
        settings.setValue("saveResolution", QString::fromStdString(mSaveResolution));
        mUi->comboBoxResolution->setCurrentText(QString::fromStdString(mSaveResolution));
    }
}

void settings::configUpdate() {
    // Save to config file
    QSettings settings(QString::fromStdString(mConfigPath), QSettings::IniFormat);
    mSavePath = mUi->lineEditSavePath->text().toStdString();
    settings.setValue("savePath", QString::fromStdString(mSavePath));
    mSaveFormat = mUi->comboBoxFormat->currentText().toStdString();
    settings.setValue("saveFormat", QString::fromStdString(mSaveFormat));
    mSaveResolution = mUi->comboBoxResolution->currentText().toStdString();
    settings.setValue("saveResolution", QString::fromStdString(mSaveResolution));
    spdlog::info("Config updated");
}

void settings::selectSavePath() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    // open at ui->lineEditSavePath->text()
    dialog.setDirectory(mUi->lineEditSavePath->text());
    dialog.setWindowTitle("Select Folder");
    if (dialog.exec()) {
        QString path = dialog.selectedFiles().first();
        mUi->lineEditSavePath->setText(path);
    }
}
