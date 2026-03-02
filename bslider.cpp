#include "bslider.h"

bSlider::bSlider(QWidget* eltern) : Slider(eltern)
{
    this->setObjectName("Blau Slider");
    this->setOrientation(Qt::Horizontal);
    this->setGeometry(10, 210, 300, 30);
    this->setMaximum(255);
}
