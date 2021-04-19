#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    pushButtons.push_back(ui->pushButton);
    pushButtons.push_back(ui->pushButton_2);
    pushButtons.push_back(ui->pushButton_3);
    pushButtons.push_back(ui->pushButton_4);
    pushButtons.push_back(ui->pushButton_5);
    pushButtons.push_back(ui->pushButton_6);
    pushButtons.push_back(ui->pushButton_7);
    pushButtons.push_back(ui->pushButton_8);
    pushButtons.push_back(ui->pushButton_9);
    pushButtons.push_back(ui->pushButton_10);
    pushButtons.push_back(ui->pushButton_16);
    pushButtons.push_back(ui->pushButton_17);
    pushButtons.push_back(ui->pushButton_18);
    pushButtons.push_back(ui->pushButton_19);
    pushButtons.push_back(ui->pushButton_20);
    pushButtons.push_back(ui->pushButton_21);
    pushButtons.push_back(ui->pushButton_22);
    pushButtons.push_back(ui->pushButton_23);
    pushButtons.push_back(ui->pushButton_24);
    pushButtons.push_back(ui->pushButton_25);
    pushButtons.push_back(ui->pushButton_26);
    pushButtons.push_back(ui->pushButton_27);
    pushButtons.push_back(ui->pushButton_28);
    pushButtons.push_back(ui->pushButton_29);
    pushButtons.push_back(ui->pushButton_30);
    nextTurn();
}

void GameWindow::nextTurn() {
    switch (gameState) {
        case GameState::BLUE_TEAM:
            ui->label->setText("BLUE TEAM TURN");
            break;
        case GameState::RED_TEAM:
            ui->label->setText("RED TEAM TURN");
            break;
        case GameState::BLUE_CAP:
            ui->label->setText("BLUE CAPTAIN TURN");
            break;
        case GameState::RED_CAP:
            ui->label->setText("RED CAPTAIN TURN");
            break;
    }

    for (int i = 0; i < 25; i++) {
        if (gameState == GameState::BLUE_CAP || gameState == GameState::RED_CAP) {
            switch (cards[i]) {
                case CardState::BLUE:
                    pushButtons[i]->setStyleSheet("background-color: rgb(0, 0, 255);");
                    break;
                case CardState::RED:
                    pushButtons[i]->setStyleSheet("background-color: rgb(255, 0, 0);");
                    break;
                case CardState::NEUTRAL:
                    pushButtons[i]->setStyleSheet("background-color: rgb(255, 255, 255);");
                    break;
                case CardState::DEATH:
                    pushButtons[i]->setStyleSheet("background-color: rgb(100, 100, 100);");
                    break;
                case CardState::OPENED:
                    pushButtons[i]->setStyleSheet("background-color: rgb(200, 200, 200);");
                    break;
            }
        } else if (gameState == GameState::BLUE_TEAM || gameState == GameState::RED_TEAM) {
            if (cards[i] == CardState::OPENED) {
                pushButtons[i]->setStyleSheet("background-color: rgb(200, 200, 200);");
            } else {
                pushButtons[i]->setStyleSheet("background-color: rgb(255, 255, 255);");
            }
        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_pushButton_11_clicked()
{
    switch (gameState) {
        case GameState::BLUE_TEAM:
            gameState = GameState::RED_CAP;
            break;
        case GameState::RED_TEAM:
            gameState = GameState::BLUE_CAP;
            break;
        case GameState::BLUE_CAP:
            gameState = GameState::BLUE_TEAM;
            break;
        case GameState::RED_CAP:
            gameState = GameState::RED_TEAM;
            break;
    }
    nextTurn();
}
