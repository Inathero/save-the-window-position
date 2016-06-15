#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qt_windows.h>
#include <QDebug>


QHash<int , QPoint> WindowPositions;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    RECT lpRect;
    if(IsWindowVisible(hwnd)) {
        GetWindowRect(hwnd, &lpRect);
        if(WindowPositions.value((int)hwnd, QPoint(-2,-2)).x() == -2)
              WindowPositions.insert((int)hwnd, QPoint(lpRect.left, lpRect.top));
    }
    return TRUE;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    WindowPositions.clear();
    EnumWindows(EnumWindowsProc, NULL);
}

void MainWindow::on_pushButton_2_clicked()
{
    QHash<int,QPoint>::const_iterator iter = WindowPositions.constBegin();
    QHash<int,QPoint>::const_iterator end = WindowPositions.constEnd();
    QHash<int,QPoint>::iterator i;
        for (i = WindowPositions.begin(); i != WindowPositions.end(); ++i) {
        QPoint wCoord = i.value();
        HWND hwnd = (HWND)i.key();
        SetWindowPos(hwnd , NULL, wCoord.x(), wCoord.y(), NULL, NULL, SWP_NOSIZE | SWP_NOZORDER);
    }
}
