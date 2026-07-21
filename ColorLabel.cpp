#include "ColorLabel.h"
#include <QPixmap>

ColorLabel::ColorLabel(QWidget* parent, rSlider *sliderRed, gSlider *sliderGreen, bSlider *sliderBlue)
    : QLabel(parent), red(sliderRed), green(sliderGreen), blue(sliderBlue)
{
}

ColorLabel::ColorLabel(QWidget *parent) : QLabel(parent)
{
}

void ColorLabel::adjustColor(int sliderValue)
{
    QColor singleColor;
    QPixmap rgb = QPixmap(this->width(), this->height());

    if(this->objectName() == "red")
    {
        singleColor = QColor(sliderValue, 0, 0);
    }
    else if(this->objectName() == "Grün")
    {
        singleColor = QColor(0, sliderValue, 0);
    }
    else if(this->objectName() == "blue")
    {
        singleColor = QColor(0, 0, sliderValue);
    }

    rgb.fill(singleColor);

    setColor(rgb);
}

void ColorLabel::adjustColorMix()
{
    valueRed = red->value();
    valueGreen = green->value();
    valueBlue = blue->value();

    QColor mix = QColor(valueRed, valueGreen, valueBlue);
    QPixmap colorField = QPixmap(this->width(), this->height());

    colorField.fill(mix);

    setColor(colorField);
}

void ColorLabel::setColor(QPixmap rgb)
{
    this->setPixmap(rgb);
}



