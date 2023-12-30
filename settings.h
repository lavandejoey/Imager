//
// Created by lavandejoey on 29/09/23.
//
#pragma once
#ifndef IMAGER_TMP_SETTINGS_H
#define IMAGER_TMP_SETTINGS_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include "spdlog/spdlog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class settings; }
QT_END_NAMESPACE

class settings : public QDialog {
Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);

    ~settings() override;

public:
    // Default save path: QDir::homeDirPath()/Pictures/Imager
    std::string mSavePath{QDir::homePath().toStdString() + "/Pictures/Imager"};
    std::string mSaveFormat{"jpg"};
    std::string mSaveResolution{"1920x1080"};

private:
    Ui::settings *mUi;
    std::string mConfigPath{"config/Imager.ini"};

signals:

private slots:

    // "OK" triggered: configUpdate();
    void accept() override {
        configUpdate();
        QDialog::accept();
    };

    // Save Path Selecting:
    void selectSavePath();

    // Config Settings:
    void configSettings();

    void configUpdate();
};


#endif //IMAGER_TMP_SETTINGS_H
