#ifndef ColorLabel_H
#define ColorLabel_H

#include <QLabel>
#include <QColor>
#include <rslider.h>
#include <gslider.h>
#include <bslider.h>

class ColorLabel : public QLabel
{
private:
    Q_OBJECT

    int valueRed, valueGreen, valueBlue;
    rSlider *red;
    gSlider *green;
    bSlider *blue;

public:
    ColorLabel(QWidget* parent);
    ColorLabel(QWidget* parent, rSlider *sliderRed, gSlider *sliderGreen, bSlider *sliderBlue);
    void setColor(QPixmap rgb);

public slots:
    void adjustColor(int sliderValue);
    void adjustColorMix();
};

#endif // ColorLabel_H
