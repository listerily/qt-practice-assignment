//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_CONFIGLOADER_H
#define STARDEW_VALLEY_LITE_CONFIGLOADER_H

#include <string>
#include <list>

#include "DimMapConfig.h"

class QApplication;
class ConfigLoader
{
private:
    QApplication& application;

    std::list<DimMapConfig> dimInitialMapsList;
public:
    explicit ConfigLoader(QApplication&);

    void initialize();
    const std::list<DimMapConfig>& getDimMaps() const;
private:
    void initializeDimensionMaps();
};


#endif //STARDEW_VALLEY_LITE_CONFIGLOADER_H
