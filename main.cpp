#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widget w;
    w.show();
    widget w2;
    w2.show();

    return a.exec();
}
