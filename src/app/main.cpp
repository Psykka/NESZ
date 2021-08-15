#include <QApplication>
#include <QDebug>
#include "Meta.hpp"
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    qInfo() << "NESZ version: " << NESZ_VERSION;

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}