#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    // If deployment says that windows platform isn't found despite plugins directory being in the correct location
    // then uncommit the below line.
    //QCoreApplication::addLibraryPath("./");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
