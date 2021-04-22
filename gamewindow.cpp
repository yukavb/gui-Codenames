#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "qdebug.h"


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

    for (auto i: pushButtons) {
        connect(i, SIGNAL(clicked()), this, SLOT(cardChoosed()));
    }
    controller = new LocalController();
    nextTurn(controller->initRequest());
}

void GameWindow::nextTurn(GameMap gameMap) {
    if (gameMap.getState() == GameState::BLUE_CAP || gameMap.getState() == GameState::RED_CAP) {
        ui->association->setReadOnly(false);
        ui->count->setReadOnly(false);
        ui->apply->show();
    } else {
        ui->association->setReadOnly(true);
        ui->count->setReadOnly(true);
        ui->apply->hide();
    }

    switch (gameMap.getState()) {
        case GameState::BLUE_TEAM:
            ui->label->setText("ХОД КОМАНДЫ СИНИХ");
            break;
        case GameState::RED_TEAM:
            ui->label->setText("ХОД КОМАНДЫ КРАСНЫХ");
            break;
        case GameState::BLUE_CAP:
            ui->label->setText("ХОД КАПИТАНА СИНИХ");
            break;
        case GameState::RED_CAP:
            ui->label->setText("ХОД КАПИТАНА КРАСНЫХ");
            break;
    }

    for (int i = 0; i < 25; i++) {
        pushButtons[i]->setText(QString::fromStdString(gameMap.getCard(i).getWord()));

        if (gameMap.getState() == GameState::BLUE_CAP || gameMap.getState() == GameState::RED_CAP || gameMap.getCard(i).isPicked()) {
            switch (gameMap.getCard(i).getState()) {
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
        } else {
            pushButtons[i]->setStyleSheet("background-color: rgb(255, 255, 255);");
        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::cardChoosed()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    for (size_t i = 0; i < pushButtons.size(); i++) {
        if (btn == pushButtons[i]) {
            GameMap gameMap = controller->request();
            GameState gameState = gameMap.getState();
            CardState cardState = gameMap.getCard(i).getState();

            if (cardState == CardState::DEATH &&
                    (gameState == GameState::RED_TEAM || gameState == GameState::BLUE_TEAM)) {
                close();
                emit gameEnd();
                return;
            }
            bool picked = gameMap.getCard(i).isPicked();

            if (!picked && gameState == GameState::RED_TEAM) {
                ui->red->append(QString::fromStdString(gameMap.getCard(i).getWord()));
            } else if (!picked && gameState == GameState::BLUE_TEAM) {
                ui->blue->append(QString::fromStdString(gameMap.getCard(i).getWord()));
            }
            nextTurn(controller->request(i));
        }
    }
}

void GameWindow::on_apply_clicked()
{
    std::string word = ui->association->text().toStdString();
    int count = ui->count->value();
    GameMap gameMap = controller->request(word, count);
    ui->association->clear();
    ui->count->setValue(1);

    switch (gameMap.getState()) {
        case GameState::RED_TEAM:
            ui->red->append(QString(word.c_str()) + " " + QString(std::to_string(count).c_str()));
            break;

        case GameState::BLUE_TEAM:
            ui->blue->append(QString(word.c_str()) + " " + QString(std::to_string(count).c_str()));
            break;

        case GameState::RED_CAP:
        case GameState::BLUE_CAP:
            break;
    }
    nextTurn(gameMap);
}
