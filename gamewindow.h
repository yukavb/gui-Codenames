#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <vector>

enum CardState {
    BLUE,
    RED,
    NEUTRAL,
    DEATH,
    OPENED
};

enum GameState {
    BLUE_TEAM,
    RED_TEAM,
    BLUE_CAP,
    RED_CAP
};

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
    GameState gameState = BLUE_CAP;
    std::vector<QPushButton*> pushButtons;
    std::vector<CardState> cards = {NEUTRAL, BLUE,  RED,     RED,     BLUE,
                                    NEUTRAL, DEATH, RED,     BLUE,    RED,
                                    RED,     BLUE,  BLUE,    NEUTRAL, NEUTRAL,
                                    NEUTRAL, BLUE,  NEUTRAL, NEUTRAL, RED,
                                    NEUTRAL, BLUE,  RED,     BLUE,    NEUTRAL};
};

#endif // GAMEWINDOW_H
