//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_STATICOBJECTCONFIG_H
#define STARDEW_VALLEY_LITE_STATICOBJECTCONFIG_H

#include <string>
#include <list>

class StaticObjectConfig
{
public:
    class StaticObjectPart
    {
    public:
        int offsetX, offsetY;
        std::list<std::string> texturePath;
    };

    std::string id;
    std::list<StaticObjectPart> parts;
};


#endif //STARDEW_VALLEY_LITE_STATICOBJECTCONFIG_H
