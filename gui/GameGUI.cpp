#include <QDebug>

#include "gui/GameGUI.h"
#include "ui_gamegui.h"
#include "gui/GSprite.h"

GameGUI::GameGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameGUI)
{
    // Set ui component to be GameGUI
    ui->setupUi(this);
    // Set fixed size to avoid resisability
    setFixedSize(ui->graphicsView->width(), ui->graphicsView->height());
    //
    _refreshGameGUITimer.callOnTimeout(this, &GameGUI::refreshGameGUISlot);
    //
    _refreshGameGUITimer.start(GUI_OBJECTS_REFRESH_RATE_IN_MS);
}

GameGUI::~GameGUI()
{
    delete ui;
}

void GameGUI::addGScene(QString gSceneId, GScenePtr gScenePtr)
{
    _gScenesMap[gSceneId] = gScenePtr;
    _gScenesMap[gSceneId]->connectOnSetSceneRequested(this, [ = ] (QString gSceneId) {
                                                                setSceneSlot(gSceneId);
                                                            });
}

void GameGUI::setSceneSlot(QString gSceneId)
{
    if (_gScenesMap.contains(gSceneId))
    {
        //
        QGraphicsScene* scene = _gScenesMap[gSceneId].get();
        ui->graphicsView->setScene(scene);
    }
    else
    {
        qWarning() << "Warning: Provided GScene ID was not found";
    }
}

void GameGUI::refreshGameGUISlot()
{

}
