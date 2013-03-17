#include <QPainter>
#include "MyCanvas.h"
#include "NormValue.h"
#include "LineChart.h"

MyCanvas::MyCanvas(QWidget* parent) : QWidget(parent) {
    model=0;
    radio="";
}

void MyCanvas::draw() {
    update();
}

void MyCanvas::setVariable(QQueue<QPointF>* q, QString r, int t, QAbstractItemModel* d) {
    model=d;
    radio=r;
    typeData=t;
    qPoint=q;
}

void MyCanvas::paintEvent(QPaintEvent*) {
    QPainter p(this);
    if(model) {
        if(typeData==0 || typeData==1) {
            if(radio=="bar") {
                //TODO disegno il grafico a barre
            }
            else if(radio=="pie") {
                //TODO disegno il grafico a torta
            }
        }
        else if(typeData==2 && radio=="line") {
            LineChart(p, qPoint);
        }
    }
}
