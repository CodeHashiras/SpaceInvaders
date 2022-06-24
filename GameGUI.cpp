#include "GameGUI.h"
#include "ui_gamegui.h"

GameGUI::GameGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameGUI)
{
    ui->setupUi(this);
}

GameGUI::~GameGUI()
{
    delete ui;
}

