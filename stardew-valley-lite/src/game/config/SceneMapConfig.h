//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_SCENEMAPCONFIG_H
#define STARDEW_VALLEY_LITE_SCENEMAPCONFIG_H

#include <string>
#include <list>

class SceneMapConfig
{
public:
    class ObjectConfig
    {
    public:
        int posX, posY;
        std::string id;
    };
    std::string id;
    double spawnX, spawnY;
    std::list<ObjectConfig> objects;
};


#endif //STARDEW_VALLEY_LITE_SCENEMAPCONFIG_H
