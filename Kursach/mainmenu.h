#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QSize>
#include <game.h>
#include <saves.h>
#include "press_to_save.h"
#include <algorithm.h>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    Ui::MainMenu *ui;
    Saves *save_window = new Saves(0, this);
    Game *game_window = new Game(0, this);
    press_to_save *press_to_save_window = new press_to_save;
    void resizeEvent(QResizeEvent *e)
    {
        int mainmenu_h = e->size().height();
        int mainmenu_w = e->size().width();
        this->game_window->resize(mainmenu_w,mainmenu_h);
        this->save_window->resize(mainmenu_w,mainmenu_h);

    }

private slots:
    void on_StartNewGame_clicked();
    void on_LoadingSavedGame_clicked();
    void on_LoadOwnGame_clicked();


};



#endif // MAINMENU_H
