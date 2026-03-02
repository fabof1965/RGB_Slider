#include "rslider.h"

rSlider::rSlider(QWidget* eltern) : Slider(eltern)
{
    this->setObjectName("Rot Slider");
    this->setOrientation(Qt::Horizontal);
    this->setGeometry(10, 50, 300, 30);
    this->setMaximum(255);
}
