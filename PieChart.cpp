#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QQueue>
#include "PieChart.h"

#include <iostream>
using namespace std;

PieChart::PieChart(QQueue<QPointF>* queue, QGraphicsScene* scene) {
    double totalValue=0.0;
    double startAngle=0.0;
    cout << "disegno " << queue->size() << " elementi" << endl;
    for(int i=0; i<queue->size()-1; i++) {
        double value=queue->value(i).y();
        cout << "valore: " << value << endl;
        if(value > 0.0) {
            double angle=360*value/totalValue;
            QGraphicsEllipseItem* item=scene->addEllipse(0,0,600,600);
            item->setStartAngle(startAngle*16);
            item->setSpanAngle(angle*16);
            startAngle=startAngle+angle;
        }
    }
}
