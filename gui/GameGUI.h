#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QScreen>

QT_BEGIN_NAMESPACE
namespace Ui { class GameGUI; }
QT_END_NAMESPACE

class GameGUI : public QMainWindow
{
    Q_OBJECT

public:

    const int WINDOWS_MAXIMUM_WIDTH = 800;
    const int WINDOWS_MAXIMUM_HEIGHT = 600;

    GameGUI(QWidget *parent = nullptr);
    ~GameGUI();

private:
    Ui::GameGUI *ui;
};
#endif // GAMEGUI_H
