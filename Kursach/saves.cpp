#include "saves.h"
#include "ui_saves.h"

Saves::Saves(QWidget *parent, QMainWindow *parent_main) :
    QMainWindow(parent),
    ui(new Ui::Saves)
{
    par = parent_main;
    ui->setupUi(this);
}

Saves::~Saves()
{
    delete ui;
}
