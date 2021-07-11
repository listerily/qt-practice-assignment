//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_CONFIGLOADER_H
#define STARDEW_VALLEY_LITE_CONFIGLOADER_H

#include <string>
#include <list>
#include <unordered_map>

#include "DimMapConfig.h"

class QApplication;
class ConfigLoader
{
private:
    QApplication& application;

    std::unordered_map<std::string, DimMapConfig> dimInitialMapsLookup;
public:
    explicit ConfigLoader(QApplication&);

    void initialize();
private:
    void initializeDimensionMaps();
};


#endif //STARDEW_VALLEY_LITE_CONFIGLOADER_H
