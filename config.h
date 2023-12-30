//
// Created by lavandejoey on 09/10/23.
//

#ifndef IMAGER_TMP_CONFIG_H
#define IMAGER_TMP_CONFIG_H

#include <iostream>
#include <string>

class config {
public:
    config() = default;

    ~config() = default;

public:

private:
    std::string mConfigPath{"config/Imager.ini"};

    void saveConfig();
};


#endif //IMAGER_TMP_CONFIG_H
