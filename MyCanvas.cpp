#include <QPainter>
#include <QMessageBox>
#include "MyCanvas.h"

#include <iostream>
using namespace std;

MyCanvas::MyCanvas(QWidget* parent) : QWidget(parent) {
    model=0;
    radio="";
}

void MyCanvas::draw() {
    update();
}

void MyCanvas::setVariable(QString r, QAbstractItemModel* d) {
    model=d;
    radio=r;
}

void MyCanvas::paintEvent(QPaintEvent*) {
    QPainter p(this);
    if(model) {
        if(radio=="line") {
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
        }
    }
}
