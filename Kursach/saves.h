#ifndef SAVES_H
#define SAVES_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QSize>

namespace Ui {
class Saves;
}

class Saves : public QMainWindow
{
    Q_OBJECT

public:
    QMainWindow* par;
    explicit Saves(QWidget *parent = 0, QMainWindow* parent_main = NULL);
    ~Saves();
    Ui::Saves *ui;

private slots:
    void on_BackToMainMenu_clicked();

public:
void resizeEvent(QResizeEvent *e)
{
    int save_h = e->size().height();
    int save_w = e->size().width();
    this->par->resize(save_w,save_h);
}
};

#endif // SAVES_H
