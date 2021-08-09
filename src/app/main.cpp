#include <iostream>
#include <QApplication>
#include "Meta.hpp"
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    std::cout << "NESZ version: " << NESZ_VERSION << std::endl;

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}