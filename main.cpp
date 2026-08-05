#include "rgb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RGB* rgbWindow = new RGB();
    rgbWindow->show();

    return a.exec();
}
