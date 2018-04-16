#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QResizeEvent>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_StartNewGame_clicked() //меню->новая игра
{
    this->close();
    game_window->show();
}

void MainMenu::on_LoadingSavedGame_clicked() //меню->сохраненные
{
    this->close();
    save_window->show();
}

void Saves::on_BackToMainMenu_clicked() //сохранение ->меню
{
    this->close();
    this->par->show();
}

void Game::on_exit_button_clicked() //игра->меню
{
    this->close();
    this->par->show();
}

void MainMenu::on_LoadOwnGame_clicked() //выбор файла игры
{
    QString fileName=QFileDialog::getOpenFileName(this,("Выбрать игру"),"C:/",("Файл игры (*.txt)"));
    game_window->ui->textBrowser->clear();
    game_window->ui->textBrowser->append("> "+fileName+"\n");
    tree_element::creating_head(fileName, this->game_window, this->save_window, this->press_to_save_window);
}
