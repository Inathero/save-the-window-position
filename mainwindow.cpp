#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qt_windows.h>

//Simple hash for window ID and position
QHash<HWND , RECT> WindowPositions;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    RECT lpRect;
    if(IsWindowVisible(hwnd)) {
        GetWindowRect(hwnd, &lpRect);
        if(WindowPositions.value(hwnd, RECT(-2,-2,0,0)).left == -2)
              WindowPositions.insert(hwnd, lpRect);
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
    QHash<HWND,QPoint>::const_iterator iter = WindowPositions.constBegin();
    QHash<HWND,QPoint>::const_iterator end = WindowPositions.constEnd();
    QHash<HWND,QPoint>::iterator i;

    for (i = WindowPositions.begin(); i != WindowPositions.end(); ++i) {
        RECT wCoord = i.value();
        HWND hwnd = i.key();
        SetWindowPos(hwnd , NULL, wCoord.left, wCoord.top, wCoord.right, wCoord.bottom, SWP_NOZORDER);
    }
}
