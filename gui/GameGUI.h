#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QScreen>
#include <QTimer>

#include "gui/GScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameGUI; }
QT_END_NAMESPACE

class GameGUI : public QMainWindow
{
    Q_OBJECT

public:

    const int WINDOWS_MAXIMUM_WIDTH = 800;
    const int WINDOWS_MAXIMUM_HEIGHT = 600;
    const int GUI_OBJECTS_REFRESH_RATE_IN_MS = 10; ///<

    GameGUI(QWidget *parent = nullptr);
    ~GameGUI();

private slots:

    /**
     * @brief setSceneSlot
     * @param gSceneId
     */
    void setSceneSlot(QString gSceneId);

    /**
     * @brief refreshGameGUISlot
     */
    void refreshGameGUISlot();

private:

    /**
     * @brief addGScene
     * @param gSceneId
     * @param gScenePtr
     */
    void addGScene(QString gSceneId, GScenePtr gScenePtr);

    Ui::GameGUI *ui;

    //
    QTimer _refreshGameGUITimer;

    //
    QMap<QString, GScenePtr> _gScenesMap;
};
#endif // GAMEGUI_H
