#ifndef PRESS_TO_SAVE_H
#define PRESS_TO_SAVE_H

#include <QMainWindow>

namespace Ui {
class press_to_save;
}

class press_to_save : public QMainWindow
{
    Q_OBJECT

public:
    explicit press_to_save(QWidget *parent = 0);
    ~press_to_save();
    Ui::press_to_save *ui;
};

#endif // PRESS_TO_SAVE_H
