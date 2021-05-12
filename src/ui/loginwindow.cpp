#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    gameWindow = new GameWindow;
    settingsWindow = new SettingsWindow;
    connect(gameWindow, &GameWindow::backToLogin, this, &LoginWindow::newGame);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_start_button_clicked()
{
    hide();
    gameWindow->show();
}

void LoginWindow::on_settings_button_clicked()
{
    settingsWindow->show();
}

void LoginWindow::newGame() {
    show();
    delete gameWindow;
    gameWindow = new GameWindow;
}
