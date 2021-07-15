//
// Created by listerily on 2021/7/6.
//

#include "ConfigLoader.h"

#include <QResource>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

ConfigLoader::ConfigLoader(QApplication & app) : application(app)
{

}

void ConfigLoader::initialize()
{
    initializeSceneMaps();
}

void ConfigLoader::initializeSceneMaps()
{
    QFile resource(":/svl/text/config/scenes/scenes_manifest.json");
    if(!resource.open(QFile::ReadOnly))
        return;
    QJsonDocument document(QJsonDocument::fromJson(resource.readAll()));
    auto worldManifestList = document.object()["scenes"].toArray();
    for(auto const& manifestItem : worldManifestList)
    {
        QFile manifestItemResFile(":/svl/text/config/scenes/" + manifestItem.toString());
        if(!manifestItemResFile.open(QFile::ReadOnly))
            continue;
        QJsonDocument document_item(QJsonDocument::fromJson(manifestItemResFile.readAll()));
        const auto& manifestObject = document_item.object();
        SceneMapConfig newConfig;
        newConfig.id = manifestObject["id"].toString().toStdString();
        newConfig.spawnX = manifestObject["spawn"][0].toDouble();
        newConfig.spawnY = manifestObject["spawn"][1].toDouble();
        auto objects = manifestObject["objects"].toArray();
        for(const auto& objectItem : objects)
        {
            SceneMapConfig::ObjectConfig newObject;
            newObject.posX = objectItem.toObject()["pos"].toArray()[0].toInt();
            newObject.posY = objectItem.toObject()["pos"].toArray()[1].toInt();
            newObject.id = objectItem.toObject()["id"].toString().toStdString();
            newConfig.objects.insert(newConfig.objects.end(), std::move(newObject));
        }
        sceneInitialMapsList.insert(sceneInitialMapsList.end(), std::move(newConfig));
    }
}

const std::list<SceneMapConfig> &ConfigLoader::getSceneMaps() const
{
    return sceneInitialMapsList;
}
