#include "src/ui/loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;

//#ifdef __unix__

    QCoreApplication::addLibraryPath("/lib/x86_64-linux-gnu/");

//#endif
    w.show();
    return a.exec();
}
