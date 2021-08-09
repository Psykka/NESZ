#include "MainWindow.hpp"
#include <QWidget>

MainWindow::MainWindow()
{
    QWidget *central = new QWidget;

    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
}