#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>

namespace Ui {
class SettingsWindow;
}

struct Setting {

    bool isLocal = true;
    unsigned numPlayers = 4;

};

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
