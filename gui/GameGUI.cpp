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
}

GameGUI::~GameGUI()
{
    delete ui;
}

