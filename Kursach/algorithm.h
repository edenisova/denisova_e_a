#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QString>
#include <QObject>
#include <QFile>
#include <QMainWindow>
#include <QTextBrowser>
#include <QPushButton>
#include "game.h"
#include "ui_game.h"
#include "saves.h"
#include "ui_saves.h"
#include <QSignalMapper>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>
#include <QJsonValue>
#include <QJsonArray>
#include "press_to_save.h"
#include "ui_press_to_save.h"

class tree_element
{
private:
    QString text;
    QString on_button_text;

public:
    int ID = 0;
    tree_element *left = 0, *middle = 0, *right = 0, *parent = 0;

    void set_text(QString text, QString on_button_text)
    {
        this->text = text;
        this->on_button_text = on_button_text;
    }

    void get_text(QTextBrowser *text_browser)
    {
        text_browser->append("> "+this->text+"\n");
    }

    void delete_text(QTextBrowser *text_browser)
    {
        text_browser->clear();
    }

    void set_button(QPushButton *button)
    {
        button->setText(this->on_button_text);
    }

    tree_element(QString text, QString on_button_text)//конструктор
    {
        set_text(text,on_button_text);
    }
    tree_element(QString text, QString on_button_text, tree_element *parent)//конструктор
    {
        set_text(text,on_button_text);
        this->parent = parent;
    }

    static void creating_head(QString fileName, Game *start_game, Saves *save_game, press_to_save *press_to_save_window);



    static void recursive_tree(Game *start_game, QJsonArray **gamearr, tree_element* head, tree_element** ssave_1, tree_element** ssave_2, tree_element** ssave_3, tree_element** ssave_4)
    {
        int ID = head->ID;
        if ((*gamearr)->at(0).toObject().value("SaveID_1").toInt() == ID)
        {
            *ssave_1 = head;
        }
        if ((*gamearr)->at(0).toObject().value("SaveID_2").toInt() == ID)
        {
            *ssave_2 = head;
        }
        if ((*gamearr)->at(0).toObject().value("SaveID_3").toInt() == ID)
        {
            *ssave_3 = head;
        }
        if ((*gamearr)->at(0).toObject().value("SaveID_4").toInt() == ID)
        {
            *ssave_4 = head;
        }
        for (int i = 1; i < (*gamearr)->size(); i++)
        {
            if (((*gamearr)->at(i).toObject().value("Parent") == ID)&&((*gamearr)->at(i).toObject().value("Level") == "Left"))
            {
                tree_element *left = new tree_element((*gamearr)->at(i).toObject().value("Text").toString(),(*gamearr)->at(i).toObject().value("Button").toString(),head);
                head->left = left;
                left->ID = (*gamearr)->at(i).toObject().value("ID").toInt();
                recursive_tree(start_game, gamearr, left, ssave_1, ssave_2, ssave_3, ssave_4);
                break;
            }
        }
        for (int i = 1; i < (*gamearr)->size(); i++)
        {
            if (((*gamearr)->at(i).toObject().value("Parent") == ID)&&((*gamearr)->at(i).toObject().value("Level") == "Middle"))
            {
                tree_element *middle = new tree_element((*gamearr)->at(i).toObject().value("Text").toString(),(*gamearr)->at(i).toObject().value("Button").toString(),head);
                head->middle = middle;
                middle->ID = (*gamearr)->at(i).toObject().value("ID").toInt();
                recursive_tree(start_game, gamearr, middle, ssave_1, ssave_2, ssave_3, ssave_4);
                break;
            }
        }
        for (int i = 1; i < (*gamearr)->size(); i++)
        {
            if (((*gamearr)->at(i).toObject().value("Parent") == ID)&&((*gamearr)->at(i).toObject().value("Level") == "Right"))
            {
                tree_element *right = new tree_element((*gamearr)->at(i).toObject().value("Text").toString(),(*gamearr)->at(i).toObject().value("Button").toString(),head);
                head->right = right;
                right->ID = (*gamearr)->at(i).toObject().value("ID").toInt();
                recursive_tree(start_game, gamearr, right, ssave_1, ssave_2, ssave_3, ssave_4);
                break;
            }
        }
    }

    static void save_to_file(tree_element *head, Game *start_game, Saves *save_game, QJsonArray **gamearr, QFile* gamefile_p, QJsonDocument *gamedoc_p, press_to_save *press_to_save_window)
    {
        static QJsonObject obj1 = (*gamearr)->at(0).toObject();

        press_to_save_window->show();
        QObject::connect(press_to_save_window->ui->Save1, &QPushButton::clicked, [=]() { obj1.remove("SaveID_1"); });
        QObject::connect(press_to_save_window->ui->Save1, &QPushButton::clicked, [=]() { obj1.insert("SaveID_1", QJsonValue(head->ID)); });
        QObject::connect(press_to_save_window->ui->Save1, &QPushButton::clicked, [=]() { (*gamearr)->replace(0,obj1); });
//        QObject::connect(press_to_save_window->ui->Save1, &QPushButton::clicked, [=]() { gamedoc_p->setArray(**gamearr); });
//        QObject::connect(press_to_save_window->ui->Save1, &QPushButton::clicked, [=]() { gamefile_p->resize(0); });
//        QObject::connect(press_to_save_window->ui->Save1, &QPushButton::clicked, [=]() { gamefile_p->write(gamedoc_p->toJson()); });
        QObject::connect(press_to_save_window->ui->Save2, &QPushButton::clicked, [=]() { obj1.remove("SaveID_2"); });
        QObject::connect(press_to_save_window->ui->Save2, &QPushButton::clicked, [=]() { obj1.insert("SaveID_2", QJsonValue(head->ID)); });
        QObject::connect(press_to_save_window->ui->Save2, &QPushButton::clicked, [=]() { (*gamearr)->replace(0,obj1); });
        QObject::connect(press_to_save_window->ui->Save3, &QPushButton::clicked, [=]() { obj1.remove("SaveID_3"); });
        QObject::connect(press_to_save_window->ui->Save3, &QPushButton::clicked, [=]() { obj1.insert("SaveID_3", QJsonValue(head->ID)); });
        QObject::connect(press_to_save_window->ui->Save3, &QPushButton::clicked, [=]() { (*gamearr)->replace(0,obj1); });
        QObject::connect(press_to_save_window->ui->Save4, &QPushButton::clicked, [=]() { obj1.remove("SaveID_4"); });
        QObject::connect(press_to_save_window->ui->Save4, &QPushButton::clicked, [=]() { obj1.insert("SaveID_4", QJsonValue(head->ID)); });
        QObject::connect(press_to_save_window->ui->Save4, &QPushButton::clicked, [=]() { (*gamearr)->replace(0,obj1); });
        QObject::connect(press_to_save_window->ui->Save1, &QPushButton::clicked, press_to_save_window, &press_to_save::close);
        QObject::connect(press_to_save_window->ui->Save2, &QPushButton::clicked, press_to_save_window, &press_to_save::close);
        QObject::connect(press_to_save_window->ui->Save3, &QPushButton::clicked, press_to_save_window, &press_to_save::close);
        QObject::connect(press_to_save_window->ui->Save4, &QPushButton::clicked, press_to_save_window, &press_to_save::close);
        gamedoc_p->setArray(**gamearr);
        gamefile_p->resize(0);
        gamefile_p->write(gamedoc_p->toJson());
        if ((*gamearr)->at(0).toObject().value("SaveID_1").toInt() == 8)
            start_game->ui->textBrowser->append("true");
    }

    static void parsing_tree(tree_element *head, Game *start_game, Saves *save_game, tree_element* save_1, tree_element* save_2, tree_element* save_3, tree_element* save_4, QJsonArray** gamearr, QFile* gamefile_p, QJsonDocument *gamedoc_p, press_to_save *press_to_save_window)
    {
        QObject::disconnect(start_game->ui->action4, &QPushButton::clicked, 0, 0);
        QObject::disconnect(start_game->ui->action1, &QPushButton::clicked, 0, 0);
        QObject::disconnect(start_game->ui->action2, &QPushButton::clicked, 0, 0);
        QObject::disconnect(start_game->ui->action3, &QPushButton::clicked, 0, 0);
        QObject::disconnect(save_game->ui->Save1, &QPushButton::clicked, 0, 0);
        QObject::disconnect(save_game->ui->Save2, &QPushButton::clicked, 0, 0);
        QObject::disconnect(save_game->ui->Save3, &QPushButton::clicked, 0, 0);
        QObject::disconnect(save_game->ui->Save4, &QPushButton::clicked, 0, 0);
        QObject::disconnect(start_game->ui->save_button,&QPushButton::clicked, 0, 0);
        QObject::connect(start_game->ui->save_button,&QPushButton::clicked, [=]() { save_to_file(head, start_game, save_game, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        QObject::connect(save_game->ui->Save1, &QPushButton::clicked, save_game, &Saves::close);
        QObject::connect(save_game->ui->Save2, &QPushButton::clicked, save_game, &Saves::close);
        QObject::connect(save_game->ui->Save3, &QPushButton::clicked, save_game, &Saves::close);
        QObject::connect(save_game->ui->Save4, &QPushButton::clicked, save_game, &Saves::close);
        QObject::connect(save_game->ui->Save1, &QPushButton::clicked, start_game, &Game::show);
        QObject::connect(save_game->ui->Save2, &QPushButton::clicked, start_game, &Game::show);
        QObject::connect(save_game->ui->Save3, &QPushButton::clicked, start_game, &Game::show);
        QObject::connect(save_game->ui->Save4, &QPushButton::clicked, start_game, &Game::show);
        QObject::connect(save_game->ui->Save1, &QPushButton::clicked, [=]() { parsing_tree(save_1, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        QObject::connect(save_game->ui->Save2, &QPushButton::clicked, [=]() { parsing_tree(save_2, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        QObject::connect(save_game->ui->Save3, &QPushButton::clicked, [=]() { parsing_tree(save_3, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        QObject::connect(save_game->ui->Save4, &QPushButton::clicked, [=]() { parsing_tree(save_4, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        head->get_text(start_game->ui->textBrowser);
//        if ((*gamearr)->isEmpty())//решить проблему с передачей указателя
//            start_game->ui->textBrowser->append("Empty");
//        else
//            start_game->ui->textBrowser->append("NotEmpty");
//        start_game->ui->textBrowser->append((*gamearr)->at(2).toObject().value("Text").toString());
        if (head->parent)
        {
            start_game->ui->action4->setEnabled(true);
            QObject::connect(start_game->ui->action4, &QPushButton::clicked, [=]() { parsing_tree(head->parent, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        }
        else
        {
            start_game->ui->action4->setDisabled(true);
        }
        if (head->left)
        {
            start_game->ui->action1->setEnabled(true);
            head->left->set_button(start_game->ui->action1);
            QObject::connect(start_game->ui->action1, &QPushButton::clicked, [=]() { parsing_tree(head->left, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        }
        else
        {
            start_game->ui->action1->setDisabled(true);
        }


        if (head->middle)
        {
            start_game->ui->action2->setEnabled(true);
            head->middle->set_button(start_game->ui->action2);
            QObject::connect(start_game->ui->action2, &QPushButton::clicked, [=]() { parsing_tree(head->middle, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        }
        else
        {
            start_game->ui->action2->setDisabled(true);
        }


        if (head->right)
        {
            start_game->ui->action3->setEnabled(true);
            head->right->set_button(start_game->ui->action3);
            QObject::connect(start_game->ui->action3, &QPushButton::clicked, [=]() { parsing_tree(head->right, start_game, save_game, save_1, save_2, save_3, save_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);});
        }
        else
        {
            start_game->ui->action3->setDisabled(true);
        }

    }
};

#endif // ALGORITHM_H
