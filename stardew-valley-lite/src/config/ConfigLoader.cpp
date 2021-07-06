//
// Created by listerily on 2021/7/6.
//

#include "config/ConfigLoader.h"

#include <QResource>
#include <QJsonObject>
#include <QJsonArray>

ConfigLoader::ConfigLoader(QApplication & app) : application(app)
{

}
void ConfigLoader::initialize()
{
    initializeStaticObjectConfig();
}

StaticObjectConfig const& ConfigLoader::getTexturesForStaticObject(const std::string &id) const
{
    return staticObjectTexturesLookup.at(id);
}

void ConfigLoader::initializeStaticObjectConfig()
{
    QResource resource(":/svl/text/config/static/static_object.json");
    QJsonValue manifest(resource.uncompressedData().data());
    auto data = manifest["data"].toArray();
    for(auto const& item : data)
    {
        StaticObjectConfig newConfig;
        newConfig.id = item.toObject()["id"].toString().toStdString();
        auto parts = item.toObject()["parts"].toArray();
        for(auto const& part : parts)
        {
            StaticObjectConfig::StaticObjectPart newPart;
            newPart.offsetX = part.toObject()["offset"].toArray()[0].toInt();
            newPart.offsetY = part.toObject()["offset"].toArray()[1].toInt();
            auto texturesArray = part.toObject()["textures"].toArray();
            for(auto const& textureItem : texturesArray)
            {
                newPart.texturePath.insert(newPart.texturePath.end(),
                                           textureItem.toString().toStdString());
            }
            newConfig.parts.insert(newConfig.parts.end(),
                                   std::move(newPart));
        }
        staticObjectTexturesLookup[newConfig.id] = std::move(newConfig);
    }
}