//
// Created by lavandejoey on 21/09/23.
//

#include <qtextstream.h>
#include "Configs.h"

void Configs::initImager() {
    /// For the first time, init with default configs.
    // Get the application's configuration directory
    QString configDir = QCoreApplication::applicationDirPath() + "/config/";
    QString configFile = configDir + "Imager.yaml";

    // Check if the config file exists
    QFile file(configFile);
    if (file.exists()) {
        loadConfigSettings(configFile);
    } else {
        createDefaultConfig();
    }
}

void Configs::loadConfigSettings(const QString &configFile) {
    /// Read the config file and load the settings

}

void Configs::createDefaultConfig(){
    /// Create a default config file
}