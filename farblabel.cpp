#include "farblabel.h"
#include <QPixmap>

Farblabel::Farblabel(QWidget* eltern, rSlider* sliderRot, gSlider* sliderGruen, bSlider* sliderBlau)
    : QLabel(eltern), rot(sliderRot), gruen(sliderGruen), blau(sliderBlau)
{
}

Farblabel::Farblabel(QWidget *eltern) : QLabel(eltern)
{
}

void Farblabel::farbeFestlegen(int sliderWert)
{
    QColor einzelFarbe;
    QPixmap rgb = QPixmap(this->width(), this->height());

    if(this->objectName() == "Rot")
    {
        einzelFarbe = QColor(sliderWert, 0, 0);
    }
    else if(this->objectName() == "Grün")
    {
        einzelFarbe = QColor(0, sliderWert, 0);
    }
    else if(this->objectName() == "Blau")
    {
        einzelFarbe = QColor(0, 0, sliderWert);
    }

    rgb.fill(einzelFarbe);

    farbeSetzen(rgb);
}

void Farblabel::mischfarbeFestlegen()
{
    wertRot = rot->value();
    wertGruen = gruen->value();
    wertBlau = blau->value();

    QColor mischung = QColor(wertRot, wertGruen, wertBlau);
    QPixmap farbFeld = QPixmap(this->width(), this->height());

    farbFeld.fill(mischung);

    farbeSetzen(farbFeld);
}

void Farblabel::farbeSetzen(QPixmap rgb)
{
    this->setPixmap(rgb);
}



