#include "GScene.h"

GScene::GScene()
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
