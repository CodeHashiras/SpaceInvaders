#include "GScene.h"

GScene::GScene(std::shared_ptr<QMap<QString, GScenePtr>> gScenesMapPtr)
    : _gScenesMapPtr(gScenesMapPtr)
{
}

void GScene::refreshGSceneGUI()
{

}

bool GScene::connectOnSetSceneRequested(std::function<void(GScenePtr)> func, QObject* qObject)
{
    bool connected = connect(this, &GScene::signalSetSceneRequested, qObject, func);
    return connected;
}


void GScene::addSpriteToSceneGUI(GSpritePtr gSpritePtr)
{
    this->addItem(gSpritePtr.get());
}


void GScene::setIdToSpriteImagePath(QString Id, QString imagePath)
{
    _pathToSpriteID[Id] = imagePath;
}


QString GScene::getPathToSprite(QString Id)
{
    return _pathToSpriteID[Id];
}


void GScene::changeGScene(QString gSceneId)
{
    emit signalSetSceneRequested(_gScenesMapPtr->value(gSceneId));
}
