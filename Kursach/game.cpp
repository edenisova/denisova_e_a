#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent, QMainWindow *parent_main) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    par = parent_main;
    ui->setupUi(this);
}


Game::~Game()
{
    delete ui;
}
