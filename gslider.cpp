#include "gslider.h"

gSlider::gSlider(QWidget* parent) : Slider(parent)
{
    this->setObjectName("Grün Slider");
    this->setOrientation(Qt::Horizontal);
    this->setGeometry(10, 130, 300, 30);
    this->setMaximum(255);
}


