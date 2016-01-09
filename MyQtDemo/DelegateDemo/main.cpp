#include "deletedemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DeleteDemo w;
    w.show();

    return a.exec();
}
