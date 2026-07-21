#include "rgb.h"
#include <QPixmap>

RGB::RGB()
{
    setupUI();
    setStartColor(colorRed);
    setStartColor(colorGreen);
    setStartColor(colorBlue);
    setConnections();
}

RGB::~RGB() {}

void RGB::setupUI()
{
    this->resize(500, 380);

    redLabel = new QLabel("red", this);
    redLabel->setGeometry(10, 10, 300, 30);

    sliderRed = new rSlider(this);

    redLabelValue = new QLabel("0", this);
    redLabelValue->setGeometry(320, 50, 30, 30);

    greenLabel = new QLabel("Grün", this);
    greenLabel->setGeometry(10, 90, 300, 30);

    sliderGreen = new gSlider(this);

    greenLabelValue = new QLabel("0", this);
    greenLabelValue->setGeometry(320, 130, 30, 30);

    blueLabel = new QLabel("blue", this);
    blueLabel->setGeometry(10, 170, 300, 30);

    sliderBlue = new bSlider(this);

    blueLabelValue = new QLabel("0", this);
    blueLabelValue->setGeometry(320, 210, 30, 30);

    //die Farbe red
    colorRed = new ColorLabel(this);
    colorRed->setGeometry(360, 50, 30, 30);
    colorRed->setObjectName("Red");

    //die Farbe grün
    colorGreen = new ColorLabel(this);
    colorGreen->setObjectName("Green");
    colorGreen->setGeometry(360, 130, 30, 30);

    //die Farbe blue
    colorBlue = new ColorLabel(this);
    colorBlue->setObjectName("Blue");
    colorBlue->setGeometry(360, 210, 30, 30);

    //die rgbColorMix aus red, grün und blue
    rgbColorMix = new ColorLabel(this, sliderRed, sliderGreen, sliderBlue);
    rgbColorMix->setObjectName("rgbColorMix");
    rgbColorMix->setGeometry(120, 250, 90, 90);
    setStartColor(rgbColorMix);

    rgbColorMixLabel = new QLabel("rgbColorMix", this);
    rgbColorMixLabel->setGeometry(135, 350, 60, 30);
}

void RGB::setConnections()
{
    //für den Slider der Farbe red2
    QObject::connect(sliderRed, SIGNAL(valueChanged(int)), redLabelValue, SLOT(setNum(int)));
    QObject::connect(sliderRed, SIGNAL(valueChanged(int)), colorRed, SLOT(adjustColor(int)));
    QObject::connect(sliderRed, SIGNAL(valueChanged(int)), rgbColorMix, SLOT(adjustColorMix()));

    //für den Slider der Farbe grün
    QObject::connect(sliderGreen, SIGNAL(valueChanged(int)), greenLabelValue, SLOT(setNum(int)));
    QObject::connect(sliderGreen, SIGNAL(valueChanged(int)), colorGreen, SLOT(adjustColor(int)));
    QObject::connect(sliderGreen, SIGNAL(valueChanged(int)), rgbColorMix, SLOT(adjustColorMix()));

    //für den Slider der Farbe blue
    QObject::connect(sliderBlue, SIGNAL(valueChanged(int)), blueLabelValue, SLOT(setNum(int)));
    QObject::connect(sliderBlue, SIGNAL(valueChanged(int)), colorBlue, SLOT(adjustColor(int)));
    QObject::connect(sliderBlue, SIGNAL(valueChanged(int)), rgbColorMix, SLOT(adjustColorMix()));
}

void RGB::setStartColor(ColorLabel* label)
{
    QPixmap colorField = QPixmap(label->width(), label->height());
    farbFeld.fill(QColor(Qt::black));
    label->setPixmap(colorField); //zu Programmstart schwarz

}
