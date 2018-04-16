#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "game.h"
#include "ui_game.h"
#include "saves.h"
#include "ui_saves.h"
#include <QApplication>
#include "algorithm.cpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu *start = new MainMenu;
    start->show();
    return a.exec();
}
