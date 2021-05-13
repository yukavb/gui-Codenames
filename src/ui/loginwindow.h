#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <src/ui/gamewindow.h>
#include <src/ui/settingswindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_start_button_clicked();

    void on_settings_button_clicked();

    void newGame();

private:
    Ui::LoginWindow *ui;
    GameWindow *gameWindow;
    SettingsWindow *settingsWindow;
};
#endif // LOGINWINDOW_H
