#include "rslider.h"

rSlider::rSlider(QWidget* parent) : Slider(parent)
{
    this->setObjectName("red_Slider");
    this->setOrientation(Qt::Horizontal);
    this->setGeometry(10, 50, 300, 30);
    this->setMaximum(255);
}
