#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    setFixedHeight(150);
    ui->horizontalWidget->hide();
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    ui->ipAddress->setValidator(ipValidator);

    QString portRange = "^([0-9]|[1-9][0-9]{4})$";
    QRegExp portRegex (portRange);
    QRegExpValidator *portValidator = new QRegExpValidator(portRegex, this);
    ui->port->setValidator(portValidator);

    ui->accept->move(ui->accept->x(), 120);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_network_clicked()
{
    setFixedHeight(220);
    ui->accept->move(ui->accept->x(), 190);
    ui->horizontalWidget->show();
}

void SettingsWindow::on_local_clicked()
{
    setFixedHeight(150);
    ui->accept->move(ui->accept->x(), 120);
    ui->horizontalWidget->hide();
}
