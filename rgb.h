#ifndef RGB_H
#define RGB_H

#include <QMainWindow>
#include <rslider.h>
#include <gslider.h>
#include <bslider.h>
#include <farblabel.h>

class RGB : public QMainWindow
{
private:
    rSlider* rotSlider;
    gSlider* gruenSlider;
    bSlider* blauSlider;
    Farblabel* farbeRot, *farbeGruen, *farbeBlau, *mischfarbe;
    QLabel* rotLabel, *rotLabelWert, *gruenLabel, *gruenLabelWert, *blauLabel, *blauLabelWert, *mischfarbeLabel;

public:
    RGB();
    ~RGB();
    void setupUI();
    void setConnections();
    void setStartColor(Farblabel* label);
};
#endif // RGB_H
