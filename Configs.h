//
// Created by lavandejoey on 21/09/23.
//
#pragma once
#ifndef IMAGER_CONFIGS_H
#define IMAGER_CONFIGS_H

#include <qstring.h>
#include <QFile>
#include <QCoreApplication>


class Configs {
public:
    const QString mqstrAppName;
    const QString mqstrAppVersion;

    Configs() {
        initImager();
    }

    ~Configs() = default;

private:

    void initImager();

    void loadConfigSettings(const QString &configFile);

    void createDefaultConfig();
};


#endif //IMAGER_CONFIGS_H
