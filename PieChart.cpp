#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QQueue>
#include "PieChart.h"

PieChart::PieChart(QQueue<QPointF>* queue, QGraphicsScene* scene) {
    double startAngle=0.0;
    for(int i=0; i<queue->size(); i++) {
        double value=queue->value(i).y();
        if(value > 0.0) {
            double angle=360*value/100;
            QGraphicsEllipseItem* item=scene->addEllipse(0,0,600,600);
            item->setStartAngle(startAngle*16);
            item->setSpanAngle(angle*16);
            startAngle=startAngle+angle;
        }
    }
}
