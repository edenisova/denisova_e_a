#include "press_to_save.h"
#include "ui_press_to_save.h"

press_to_save::press_to_save(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::press_to_save)
{
    ui->setupUi(this);
}

press_to_save::~press_to_save()
{
    delete ui;
}
