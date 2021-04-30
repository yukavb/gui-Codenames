#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "qdebug.h"

const char LINE[] = "------------------------";

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

    for (const auto &button: pushButtons) {
        connect(button, SIGNAL(clicked()), this, SLOT(cardChoosed()));
    }
    controller = new LocalController();
    redraw(controller->initRequest());
}

void GameWindow::redraw(const GameMap* gameMap)
{
    if (gameMap->isCaptainTurn()) {
        ui->count->setValue(1);
        ui->association->clear();
    }
    ui->association->setReadOnly(gameMap->isTeamTurn());
    ui->count->setReadOnly(gameMap->isTeamTurn());

    if (gameMap->isCaptainTurn()) {
        ui->apply->show();
    } else if (gameMap->getCountWordsOnTurn() != 1) {
        ui->apply->hide();
    }

    switch (gameMap->getState()) {
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
    redrawGameMap(gameMap);
}

void GameWindow::redrawTeamGameMap(const GameMap* gameMap) {
    for (int i = 0; i < 25; i++) {
        pushButtons[i]->setText(QString::fromStdString(gameMap->getCard(i).getWord()));

        if (gameMap->getCard(i).isPicked()) {
            QString color = "color: rgb(255, 255, 255);\n";

            switch (gameMap->getCard(i).getState()) {
                case CardState::BLUE:
                    pushButtons[i]->setStyleSheet(color + "background-color: rgb(0, 0, 255);");
                    break;
                case CardState::RED:
                    pushButtons[i]->setStyleSheet(color + "background-color: rgb(255, 0, 0);");
                    break;
                case CardState::NEUTRAL:
                    pushButtons[i]->setStyleSheet(color + "background-color: rgb(185, 185, 160);");
                    break;
                case CardState::DEATH:
                    pushButtons[i]->setStyleSheet(color + "background-color: rgb(100, 100, 100);");
                    break;
            }
        } else {
            pushButtons[i]->setStyleSheet("background-color: rgb(255, 255, 255);");
        }
    }
}

void GameWindow::redrawGameMap(const GameMap* gameMap) {
    if (gameMap->isTeamTurn()) {
        redrawTeamGameMap(gameMap);
        return;
    }

    for (int i = 0; i < 25; i++) {
        pushButtons[i]->setText(QString::fromStdString(gameMap->getCard(i).getWord()));

        if (gameMap->isCaptainTurn()) {
            QString backColor = QString("background-color: ") +
                    (gameMap->getCard(i).isPicked() ? "rgb(185, 185, 160);\n" : "rgb(255, 255, 255);\n");

            switch (gameMap->getCard(i).getState()) {
                case CardState::BLUE:
                    pushButtons[i]->setStyleSheet(backColor + "color: rgb(0, 0, 255);");
                    break;
                case CardState::RED:
                    pushButtons[i]->setStyleSheet(backColor + "color: rgb(255, 0, 0);");
                    break;
                case CardState::NEUTRAL:
                    pushButtons[i]->setStyleSheet(backColor + "color: " + (gameMap->getCard(i).isPicked() ? "rgb(255, 255, 255);" : "rgb(0, 0, 0);"));
                    break;
                case CardState::DEATH:
                    pushButtons[i]->setStyleSheet(QString("background-color: rgb(0, 0, 0);\n") + "color: rgb(255, 255, 255);");
                    break;
            }
        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::cardChoosed()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    for (size_t i = 0; i < pushButtons.size(); i++) {
        if (btn == pushButtons[i]) {
            const GameMap* gameMap = controller->request();
            GameState gameState = gameMap->getState();

            if (gameMap->isCaptainTurn() ||
                gameMap->getCountWordsOnTurn() == 0) {
                return;
            }

            if (!gameMap->getCard(i).isPicked()) {
                if (gameState == GameState::RED_TEAM) {
                    ui->red->append(QString::fromStdString(gameMap->getCard(i).getWord()));
                } else if (gameState == GameState::BLUE_TEAM) {
                    ui->blue->append(QString::fromStdString(gameMap->getCard(i).getWord()));
                }
            }
            gameMap = controller->request(i);

            if (gameMap->isGameEnded() != EndState::NOT_END) {
                redraw(gameMap);
                gameEnd();
                return;
            }
            gameState = gameMap->getState();
            ui->count->setValue(gameMap->getCountWordsOnTurn());

            if (gameMap->getCountWordsOnTurn() == 0) {
                ui->apply->show();
                ui->apply->setText("Сл. ход");
                redrawTeamGameMap(gameMap);
            } else {
                redraw(gameMap);
            }

            if (gameState == GameState::BLUE_CAP) {
                ui->red->append(QString(LINE) + "\n");
            } else if (gameState == GameState::RED_CAP) {
                ui->blue->append(QString(LINE) + "\n");
            }
        }
    }
}

void GameWindow::on_apply_clicked()
{
    const GameMap* gameMap = controller->request();

    if (ui->apply->text() == "Сл. ход") {
        redraw(controller->request());
        ui->apply->setText("Подтвердить");
        return;
    } else if (ui->apply->text() == "На старт") {
        close();
        emit backToLogin();
        return;
    }
    std::string word = ui->association->text().toStdString();
    int count = ui->count->value();
    gameMap = controller->request(word, count);

    switch (gameMap->getState()) {
        case GameState::RED_TEAM:
            ui->red->append(QString(word.c_str()) + " " + QString(std::to_string(count).c_str()));
            ui->red->append(LINE);
            break;

        case GameState::BLUE_TEAM:
            ui->blue->append(QString(word.c_str()) + " " + QString(std::to_string(count).c_str()));
            ui->blue->append(LINE);
            break;

        case GameState::RED_CAP:
        case GameState::BLUE_CAP:
            break;
    }
    redraw(gameMap);
}

void GameWindow::gameEnd() {
    for (auto button : pushButtons) {
        button->setEnabled(false);
    }
    ui->apply->setText("На старт");
    ui->apply->show();
    EndState endState = controller->request()->isGameEnded();

    if (endState == EndState::RED_WINS) {
        ui->label->setText("КРАСНЫЕ ПОБЕДИЛИ!");
    } else if (endState == EndState::BLUE_WINS) {
        ui->label->setText("СИНИЕ ПОБЕДИЛИ!");
    }
}
