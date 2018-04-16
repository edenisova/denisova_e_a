#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QSize>
#include <QPushButton>

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    QMainWindow* par;
    explicit Game(QWidget *parent = 0, QMainWindow* parent_main = NULL);
    ~Game();
    Ui::Game *ui;
    void resizeEvent(QResizeEvent *e)
    {
        int game_h = e->size().height();
        int game_w = e->size().width();
        this->par->resize(game_w,game_h);
    }

private slots:
    void on_exit_button_clicked();

//    void on_save_button_clicked();
};

#endif // GAME_H
