//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_CONFIGLOADER_H
#define STARDEW_VALLEY_LITE_CONFIGLOADER_H

#include <string>
#include <list>

#include "SceneMapConfig.h"

class QApplication;
class ConfigLoader
{
private:
    QApplication& application;

    std::list<SceneMapConfig> sceneInitialMapsList;
public:
    explicit ConfigLoader(QApplication&);

    void initialize();
    const std::list<SceneMapConfig>& getSceneMaps() const;
private:
    void initializeSceneMaps();
};


#endif //STARDEW_VALLEY_LITE_CONFIGLOADER_H
