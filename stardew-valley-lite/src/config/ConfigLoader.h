//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_CONFIGLOADER_H
#define STARDEW_VALLEY_LITE_CONFIGLOADER_H

#include <string>
#include <list>
#include <unordered_map>

#include "StaticObjectConfig.h"

class QApplication;
class ConfigLoader
{
private:
    QApplication& application;

    std::unordered_map<std::string, StaticObjectConfig> staticObjectTexturesLookup;
public:
    explicit ConfigLoader(QApplication&);

    void initialize();

    StaticObjectConfig const& getTexturesForStaticObject(const std::string &id) const;
private:
    void initializeStaticObjectConfig();
};


#endif //STARDEW_VALLEY_LITE_CONFIGLOADER_H
