#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <vector>
#include "utils.h"


namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void on_pushButton_11_clicked();

private:
    void nextTurn();

    Ui::GameWindow *ui;
    GameState gameState = GameState::BLUE_CAP;
    std::vector<QPushButton*> pushButtons;
    std::vector<CardState> cards = {CardState::NEUTRAL, CardState::BLUE,  CardState::RED,     CardState::RED,     CardState::BLUE,
                                    CardState::NEUTRAL, CardState::DEATH, CardState::RED,     CardState::BLUE,    CardState::RED,
                                    CardState::RED,     CardState::BLUE,  CardState::BLUE,    CardState::NEUTRAL, CardState::NEUTRAL,
                                    CardState::NEUTRAL, CardState::BLUE,  CardState::NEUTRAL, CardState::NEUTRAL, CardState::RED,
                                    CardState::NEUTRAL, CardState::BLUE,  CardState::RED,     CardState::BLUE,    CardState::NEUTRAL};
};

#endif // GAMEWINDOW_H
