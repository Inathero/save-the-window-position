#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

//    QCoreApplication::addLibraryPath("./"); //this goddamn line right here

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
