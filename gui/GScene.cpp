#include "GScene.h"

GScene::GScene()
{
}

void GScene::refreshGSceneGUI()
{

}

bool GScene::connectOnSetSceneRequested(QObject* qObject, std::function<void(QString gSceneId)> func)
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
    emit signalSetSceneRequested(gSceneId);
}
