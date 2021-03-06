#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qt_windows.h>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_setPositions_clicked();

    void on_pushButton_getPositions_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
