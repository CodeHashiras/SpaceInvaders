#ifndef MENUSCENE_H
#define MENUSCENE_H

#include<QKeyEvent>

#include "gui/GScene.h"

class MenuScene : public GScene
{

public:

    MenuScene(std::shared_ptr<QMap<QString, GScenePtr>> gScenesMapPtr);

protected:

    void refreshGSceneGUI() override;

    void keyPressEvent(QKeyEvent *keyEvent) override;

    void keyReleaseEvent(QKeyEvent *keyEvent) override;
};

#endif // MENUSCENE_H
