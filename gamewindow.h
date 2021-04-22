#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <vector>
#include "utils.h"
#include "localcontroller.h"
#include "gamemap.h"

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
    void cardChoosed();
    void capApplied();

private:
    void nextTurn(GameMap);
    IController* controller;
    Ui::GameWindow *ui;
    std::vector<QPushButton*> pushButtons;
};

#endif // GAMEWINDOW_H
