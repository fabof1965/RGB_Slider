#include "bslider.h"

bSlider::bSlider(QWidget* parent) : Slider(parent)
{
    this->setObjectName("blue Slider");
    this->setOrientation(Qt::Horizontal);
    this->setGeometry(10, 210, 300, 30);
    this->setMaximum(255);
}
