#ifndef RGB_H
#define RGB_H

#include <QMainWindow>
#include <rslider.h>
#include <gslider.h>
#include <bslider.h>
#include <ColorLabel.h>

class RGB : public QMainWindow
{
private:
    rSlider *sliderRed;
    gSlider *sliderGreen;
    bSlider *sliderBlue;
    ColorLabel *colorRed, *colorGreen, *colorBlue, *rgbColorMix;
    QLabel *redLabel, *redLabelValue, *greenLabel, *greenLabelValue, *blueLabel, *blueLabelValue, *rgbColorMixLabel;

public:
    RGB();
    ~RGB();
    void setupUI();
    void setConnections();
    void setStartColor(ColorLabel* label);
};
#endif // RGB_H
