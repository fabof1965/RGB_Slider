#ifndef RGB_H
#define RGB_H

#include <QMainWindow>
#include <rslider.h>
#include <gslider.h>
#include <bslider.h>
#include <ColorLabel.h>
#include <QSlider>

class RGB : public QMainWindow
{
private:
    rSlider *sliderRed;
    gSlider *sliderGreen;
    bSlider *sliderBlue;
    ColorLabel *colorRed, *colorGreen, *colorBlue, *rgbColorMix;
    QLabel *redLabel, *redLabelValue, *greenLabel, *greenLabelValue, *blueLabel, *blueLabelValue, *rgbColorMixLabel;
    QString redName = "Red", greenName = "Green", blueName = "Blue", rgbName = "RGB_Color_Mix";
    int colorLabelWidth = 30, colorLabelHeight = 30, colorLabel_xPos = 360;

public:
    RGB();
    ~RGB();
    void setupUI();
    void setConnections();
    void setSignalSlotConnection(QSlider *colorSlider, QLabel *colorValueLabel, ColorLabel *color_Label);
    void setStartColor(ColorLabel* label);
    void setupColorLabel(ColorLabel *labelColor, QString colorName, int yPos);
};
#endif // RGB_H
