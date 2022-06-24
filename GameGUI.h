#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GameGUI; }
QT_END_NAMESPACE

class GameGUI : public QMainWindow
{
    Q_OBJECT

public:
    GameGUI(QWidget *parent = nullptr);
    ~GameGUI();

private:
    Ui::GameGUI *ui;
};
#endif // GAMEGUI_H
