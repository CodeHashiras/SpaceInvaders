#include "MenuScene.h"

MenuScene::MenuScene(std::shared_ptr<QMap<QString, GScenePtr>> gScenesMapPtr)
    : GScene(gScenesMapPtr)
{

}

void MenuScene::refreshGSceneGUI()
{

}

void MenuScene::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key()) {
        case Qt::Key_Enter:
            break;
        default:
            break;
    }
}

void MenuScene::keyReleaseEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key()) {
        case Qt::Key_Enter:
            break;
        default:
            break;
    }
}
