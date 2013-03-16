#include <QPainter>
#include <QQueue>
#include <QPointF>
#include "MyCanvas.h"
#include "NormValue.h"

MyCanvas::MyCanvas(QWidget* parent) : QWidget(parent) {
    model=0;
    radio="";
}

void MyCanvas::draw() {
    update();
}

void MyCanvas::setVariable(QString r, int t, QAbstractItemModel* d) {
    model=d;
    radio=r;
    typeData=t;
}

void MyCanvas::paintEvent(QPaintEvent*) {
    QPainter p(this);
    if(model) {
        QQueue<double> qDouble;
        QQueue<QPointF> qPoint;
        NormValue norm(&qDouble, &qPoint, model, typeData);
        if(typeData==0 || typeData==1) {
            //NOTE qui uso qDouble
            if(radio=="bar") {
                //TODO disegno il grafico a barre
            }
            else if(radio=="pie") {
                //TODO disegno il grafico a torta
            }
        }
        if(typeData==2 && radio=="line") {
            //NOTE qui uso qPoint
            //TODO disegno il grafico a linea
        }
    }
}


/*if(radio=="line") {
    p.setPen(QColor(Qt::black));
    p.drawRect(0,0,10,200);
}
else if(radio=="bar") {
    p.setPen(QColor(Qt::red));
    p.drawRect(0,0,200,10);
}
else if(radio=="pie") {
    p.setPen(QColor(Qt::green));
    p.drawRect(0,0,100,100);
}*/
