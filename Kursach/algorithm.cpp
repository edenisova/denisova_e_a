#include "algorithm.h"

void tree_element::creating_head(QString fileName, Game *start_game, Saves *save_game, press_to_save *press_to_save_window)
{
    tree_element *head = new tree_element("","");
    static QFile gamefile(fileName);
    static QFile *gamefile_p = &gamefile;
    gamefile.open(QIODevice::ReadWrite);

    if (gamefile.isOpen())
    {
        QString gamestr = QString::fromUtf8(gamefile.readAll());
        static QJsonDocument gamedoc = QJsonDocument::fromJson(gamestr.toUtf8());
        static QJsonDocument *gamedoc_p = &gamedoc;
        if (gamedoc.isArray())
        {
            static QJsonArray *gamearr1 = new QJsonArray(gamedoc.array());
            static QJsonArray **gamearr = &(gamearr1);

            QJsonObject gamehead;
            for (int i = 1; i < (*gamearr)->size(); i++)
            {
                if ((*gamearr)->at(i).toObject().value("ID") == 1)
                {
                    gamehead = (*gamearr)->at(i).toObject();
                    break;
                }
            }
            if (!gamehead.isEmpty())
            {
                for (int i = 1; i < (*gamearr)->size(); i++)
                {
                    if ((*gamearr)->at(i).toObject().value("ID") == (*gamearr)->at(0).toObject().value("SaveID_1").toInt())
                    {
                        save_game->ui->Save1->setText("...> "+(*gamearr)->at(i).toObject().value("Text").toString());
                        save_game->ui->Save1->setEnabled(true);
                    }
                    if ((*gamearr)->at(i).toObject().value("ID") == (*gamearr)->at(0).toObject().value("SaveID_2").toInt())
                    {
                        save_game->ui->Save2->setText("...> "+(*gamearr)->at(i).toObject().value("Text").toString());
                        save_game->ui->Save2->setEnabled(true);
                    }
                    if ((*gamearr)->at(i).toObject().value("ID") == (*gamearr)->at(0).toObject().value("SaveID_3").toInt())
                    {
                        save_game->ui->Save3->setText("...> "+(*gamearr)->at(i).toObject().value("Text").toString());
                        save_game->ui->Save3->setEnabled(true);
                    }
                    if ((*gamearr)->at(i).toObject().value("ID") == (*gamearr)->at(0).toObject().value("SaveID_4").toInt())
                    {
                        save_game->ui->Save4->setText("...> "+(*gamearr)->at(i).toObject().value("Text").toString());
                        save_game->ui->Save4->setEnabled(true);
                    }
                }
                tree_element *save_1 = new tree_element("",""), *save_2 = new tree_element("",""), *save_3 = new tree_element("",""), *save_4 = new tree_element("","");
                tree_element **ssave_1 = &save_1, **ssave_2 = &save_2, **ssave_3 = &save_3, **ssave_4 = &save_4;
                head->ID = gamehead.value("ID").toInt();
                head->set_text(gamehead.value("Text").toString(),gamehead.value("Button").toString());
                if (head->ID == (*gamearr)->at(0).toObject().value("SaveID_1").toInt())
                    *ssave_1 = head;
                if (head->ID == (*gamearr)->at(0).toObject().value("SaveID_2").toInt())
                    *ssave_2 = head;
                if (head->ID == (*gamearr)->at(0).toObject().value("SaveID_3").toInt())
                    *ssave_3 = head;
                if (head->ID == (*gamearr)->at(0).toObject().value("SaveID_4").toInt())
                    *ssave_4 = head;
                recursive_tree(start_game, gamearr, head, ssave_1, ssave_2, ssave_3, ssave_4);
                parsing_tree(head, start_game, save_game, *ssave_1, *ssave_2, *ssave_3, *ssave_4, gamearr, gamefile_p, gamedoc_p, press_to_save_window);
                gamedoc_p->setArray(**gamearr);
                gamefile_p->resize(0);
                gamefile_p->write(gamedoc_p->toJson());
            }
            else
            {
                start_game->ui->textBrowser->append("> Не удается найти начало игры, проверьте файл!!!\n");
            }
        }
        else
        {
            start_game->ui->textBrowser->append("> Некорректный файл игры!!!\n");
        }
    }
    else
    {
        start_game->ui->textBrowser->append("> Неизвестная ошибка при открытии файла!!!\n");
    }
    gamefile.close();
}



