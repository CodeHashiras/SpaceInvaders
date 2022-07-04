#include "gui/GameGUI.h"
#include "ui_gamegui.h"
#include "gui/Sprite.h"

GameGUI::GameGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameGUI)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView->x(), ui->graphicsView->y(), ui->graphicsView->width(), ui->graphicsView->height());

    ui->graphicsView->setScene(scene);

    Sprite *test_sprite = new Sprite(108, 140, ":/sprites/sprite_test.png");
    test_sprite->setFps(8);
    test_sprite->addAnimationId("PLAYER_GOING_FORWARD", 0);
    test_sprite->addAnimationId("PLAYER_GOING_BACKWARD", 1);
    test_sprite->setAnimation("PLAYER_GOING_FORWARD");
    test_sprite->setPos(346, 150);
    scene->addItem(test_sprite);


    Sprite *test_sprite2 = new Sprite(108, 140, ":/sprites/sprite_test.png");
    test_sprite2->setFps(4);
    test_sprite2->addAnimationId("PLAYER_GOING_FORWARD", 0);
    test_sprite2->addAnimationId("PLAYER_GOING_BACKWARD", 1);
    test_sprite2->setAnimation("PLAYER_GOING_BACKWARD");
    test_sprite2->setPos(346, 300);
    scene->addItem(test_sprite2);
}

GameGUI::~GameGUI()
{
    delete ui;
}

