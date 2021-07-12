//
// Created by listerily on 2021/7/6.
//

#include "ConfigLoader.h"

#include <QResource>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

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
    QJsonDocument document(QJsonDocument::fromJson(resource.uncompressedData().data()));
    auto worldManifestList = document["dimensions"].toArray();
    for(auto const& manifestItem : worldManifestList)
    {
        QResource manifestItemResFile(":/svl/text/config/dim/" + manifestItem.toString());
        QJsonDocument document_item(QJsonDocument::fromJson(manifestItemResFile.uncompressedData().data()));
        const auto& manifestObject = document_item;
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
        dimInitialMapsList.insert(dimInitialMapsList.end(), std::move(newConfig));
    }
}

const std::list<DimMapConfig> &ConfigLoader::getDimMaps() const
{
    return dimInitialMapsList;
}
