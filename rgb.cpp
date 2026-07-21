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

RGB::~RGB() {

}

void RGB::setupUI()
{
    this->resize(500, 380);

    redLabel = new QLabel(redName, this);
    redLabel->setGeometry(10, 10, 300, 30);

    sliderRed = new rSlider(this);

    redLabelValue = new QLabel("0", this);
    redLabelValue->setGeometry(320, 50, 30, 30);

    greenLabel = new QLabel(greenName, this);
    greenLabel->setGeometry(10, 90, 300, 30);

    sliderGreen = new gSlider(this);

    greenLabelValue = new QLabel("0", this);
    greenLabelValue->setGeometry(320, 130, 30, 30);

    blueLabel = new QLabel(blueName, this);
    blueLabel->setGeometry(10, 170, 300, 30);

    sliderBlue = new bSlider(this);

    blueLabelValue = new QLabel("0", this);
    blueLabelValue->setGeometry(320, 210, 30, 30);

    colorRed = new ColorLabel(this);
    setupColorLabel(colorRed, redName, 50);

    colorGreen = new ColorLabel(this);
    setupColorLabel(colorGreen, greenName, 130);

    colorBlue = new ColorLabel(this);
    setupColorLabel(colorBlue, blueName, 210);

    rgbColorMix = new ColorLabel(this, sliderRed, sliderGreen, sliderBlue);
    rgbColorMix->setGeometry(120, 250, 90, 90);
    rgbColorMix->setObjectName(rgbName);
    setStartColor(rgbColorMix);

    rgbColorMixLabel = new QLabel(rgbName, this);
    rgbColorMixLabel->setGeometry(125, 350, 80, 30);
}

void RGB::setupColorLabel(ColorLabel *labelColor, QString colorName, int yPos)
{
    labelColor->setGeometry(colorLabel_xPos, yPos, colorLabelWidth, colorLabelHeight);
    labelColor->setObjectName(colorName);
}

void RGB::setConnections()
{
    setSignalSlotConnection(sliderRed, redLabelValue, colorRed);
    setSignalSlotConnection(sliderGreen, greenLabelValue, colorGreen);
    setSignalSlotConnection(sliderBlue, blueLabelValue, colorBlue);
}

void RGB::setSignalSlotConnection(QSlider *colorSlider, QLabel *colorValueLabel, ColorLabel *color_Label)
{
    QObject::connect(colorSlider, SIGNAL(valueChanged(int)), colorValueLabel, SLOT(setNum(int)));
    QObject::connect(colorSlider, SIGNAL(valueChanged(int)), color_Label, SLOT(adjustColor(int)));
    QObject::connect(colorSlider, SIGNAL(valueChanged(int)), rgbColorMix, SLOT(adjustColorMix()));
}

void RGB::setStartColor(ColorLabel* label)
{
    QPixmap colorField = QPixmap(label->width(), label->height());
    colorField.fill(QColor(Qt::black));
    label->setPixmap(colorField);
}
