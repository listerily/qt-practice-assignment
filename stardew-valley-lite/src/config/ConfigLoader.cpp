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
    initializeDimensionMaps();
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
