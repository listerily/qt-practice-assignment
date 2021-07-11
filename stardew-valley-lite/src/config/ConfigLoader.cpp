//
// Created by listerily on 2021/7/6.
//

#include "ConfigLoader.h"

#include <QResource>
#include <QJsonObject>
#include <QJsonArray>

ConfigLoader::ConfigLoader(QApplication & app) : application(app)
{

}

void ConfigLoader::initialize()
{
    initializeStaticObjectConfig();
    initializeDimensionMaps();
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

void ConfigLoader::initializeDimensionMaps()
{
    QResource resource(":/svl/text/config/dim/dim_manifest.json");
    auto worldManifestList = QJsonValue(resource.uncompressedData().data()).toArray();
    for(auto const& manifestItem : worldManifestList)
    {
        QResource manifestItemResFile(":/svl/text/config/dim/" + manifestItem.toString());
        auto manifestObject = QJsonValue(manifestItemResFile.uncompressedData().data());
        DimMapConfig newConfig;
        newConfig.id = manifestObject["id"].toString().toStdString();
        auto objects = manifestObject["objects"].toArray();
        for(const auto& objectItem : objects)
        {
            DimMapConfig::ObjectConfig newObject;
            newObject.posX = objectItem.toObject()["pos"].toArray()[0].toInt();
            newObject.posY = objectItem.toObject()["pos"].toArray()[1].toInt();
            newObject.id = objectItem.toObject()["id"].toString().toStdString();
            newConfig.objects.insert(newConfig.objects.end(), std::move(newObject));
        }
        dimInitialMapsLookup[newConfig.id] = std::move(newConfig);
    }
}
