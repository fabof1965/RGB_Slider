#include "rgb.h"
#include <QPixmap>

RGB::RGB()
{
    setupUI();
    setStartColor(farbeRot);
    setStartColor(farbeGruen);
    setStartColor(farbeBlau);
    setConnections();
}

RGB::~RGB() {}

void RGB::setupUI()
{
    this->resize(500, 380);

    rotLabel = new QLabel("Rot", this);
    rotLabel->setGeometry(10, 10, 300, 30);

    rotSlider = new rSlider(this);

    rotLabelWert = new QLabel("0", this);
    rotLabelWert->setGeometry(320, 50, 30, 30);

    gruenLabel = new QLabel("Grün", this);
    gruenLabel->setGeometry(10, 90, 300, 30);

    gruenSlider = new gSlider(this);

    gruenLabelWert = new QLabel("0", this);
    gruenLabelWert->setGeometry(320, 130, 30, 30);

    blauLabel = new QLabel("Blau", this);
    blauLabel->setGeometry(10, 170, 300, 30);

    blauSlider = new bSlider(this);

    blauLabelWert = new QLabel("0", this);
    blauLabelWert->setGeometry(320, 210, 30, 30);

    //die Farbe rot
    farbeRot = new Farblabel(this);
    farbeRot->setGeometry(360, 50, 30, 30);
    farbeRot->setObjectName("Rot");

    //die Farbe grün
    farbeGruen = new Farblabel(this);
    farbeGruen->setObjectName("Grün");
    farbeGruen->setGeometry(360, 130, 30, 30);

    //die Farbe blau
    farbeBlau = new Farblabel(this);
    farbeBlau->setObjectName("Blau");
    farbeBlau->setGeometry(360, 210, 30, 30);

    //die Mischfarbe aus rot, grün und blau
    mischfarbe = new Farblabel(this, rotSlider, gruenSlider, blauSlider);
    mischfarbe->setObjectName("Mischfarbe");
    mischfarbe->setGeometry(120, 250, 90, 90);
    setStartColor(mischfarbe);

    mischfarbeLabel = new QLabel("Mischfarbe", this);
    mischfarbeLabel->setGeometry(135, 350, 60, 30);
}

void RGB::setConnections()
{
    //für den Slider der Farbe rot2
    QObject::connect(rotSlider, SIGNAL(valueChanged(int)), rotLabelWert, SLOT(setNum(int)));
    QObject::connect(rotSlider, SIGNAL(valueChanged(int)), farbeRot, SLOT(farbeFestlegen(int)));
    QObject::connect(rotSlider, SIGNAL(valueChanged(int)), mischfarbe, SLOT(mischfarbeFestlegen()));

    //für den Slider der Farbe grün
    QObject::connect(gruenSlider, SIGNAL(valueChanged(int)), gruenLabelWert, SLOT(setNum(int)));
    QObject::connect(gruenSlider, SIGNAL(valueChanged(int)), farbeGruen, SLOT(farbeFestlegen(int)));
    QObject::connect(gruenSlider, SIGNAL(valueChanged(int)), mischfarbe, SLOT(mischfarbeFestlegen()));

    //für den Slider der Farbe blau
    QObject::connect(blauSlider, SIGNAL(valueChanged(int)), blauLabelWert, SLOT(setNum(int)));
    QObject::connect(blauSlider, SIGNAL(valueChanged(int)), farbeBlau, SLOT(farbeFestlegen(int)));
    QObject::connect(blauSlider, SIGNAL(valueChanged(int)), mischfarbe, SLOT(mischfarbeFestlegen()));
}

void RGB::setStartColor(Farblabel* label)
{
    QPixmap farbFeld = QPixmap(label->width(), label->height());
    farbFeld.fill(QColor(Qt::black));
    label->setPixmap(farbFeld); //zu Programmstart schwarz

}
