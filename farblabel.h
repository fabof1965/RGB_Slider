#ifndef FARBLABEL_H
#define FARBLABEL_H

#include <QLabel>
#include <QColor>
#include <rslider.h>
#include <gslider.h>
#include <bslider.h>

class Farblabel : public QLabel
{
private:
    Q_OBJECT

    int wertRot, wertGruen, wertBlau;
    // QSlider* rot, *gruen, *blau;
    rSlider* rot;
    gSlider* gruen;
    bSlider* blau;

public:
    Farblabel(QWidget* eltern);
    Farblabel(QWidget* eltern, rSlider* sliderRot, gSlider* sliderGruen, bSlider* sliderBlau);
    void farbeSetzen(QPixmap rgb);

public slots:
    void farbeFestlegen(int sliderWert);
    void mischfarbeFestlegen();
};

#endif // FARBLABEL_H
