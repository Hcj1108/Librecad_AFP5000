#include "draw_rectangle.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    draw_rectangle w;
    w.show();
    return a.exec();
}
