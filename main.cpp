#include "rgb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RGB* rgbFenster = new RGB();
    rgbFenster->show();

    return a.exec();
}
