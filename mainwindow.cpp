#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qt_windows.h>

// Simple hash for window ID and position
QHash<HWND , RECT> WindowPositions;

// Reiterates processess
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    RECT lpRect;
    // If visible and not already saved, save window pos and size
    if(IsWindowVisible(hwnd)) {
        GetWindowRect(hwnd, &lpRect);
        if(WindowPositions.value(hwnd, RECT{-2,0,0,0}).left == -2)
              WindowPositions.insert(hwnd, lpRect);
    }
    return TRUE;
}

// Init
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
// Deconstruct
MainWindow::~MainWindow()
{
    delete ui;
}

// Save window's positions
void MainWindow::on_pushButton_setPositions_clicked()
{
    WindowPositions.clear();
    EnumWindows(EnumWindowsProc, NULL);
}

// Set window's positions
void MainWindow::on_pushButton_getPositions_clicked()
{
    QHash<HWND,RECT>::const_iterator iter = WindowPositions.constBegin();
    QHash<HWND,RECT>::const_iterator end = WindowPositions.constEnd();
    QHash<HWND,RECT>::iterator i;


    for (i = WindowPositions.begin(); i != WindowPositions.end(); ++i) {
        RECT wCoord = i.value();
        HWND hwnd = i.key();
        SetWindowPos(hwnd , NULL, wCoord.left, wCoord.top, wCoord.right-wCoord.left, wCoord.bottom-wCoord.top, SWP_NOZORDER);
    }
}
