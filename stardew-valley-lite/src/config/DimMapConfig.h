//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_DIMMAPCONFIG_H
#define STARDEW_VALLEY_LITE_DIMMAPCONFIG_H

#include <string>
#include <list>

class DimMapConfig
{
public:
    class ObjectConfig
    {
    public:
        int posX, posY;
        std::string id;
    };
    std::string id;
    std::list<ObjectConfig> objects;
};


#endif //STARDEW_VALLEY_LITE_DIMMAPCONFIG_H
