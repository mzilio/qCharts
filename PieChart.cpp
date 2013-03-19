#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QQueue>
#include "PieChart.h"

PieChart::PieChart(QQueue<QPointF>* queue, QGraphicsScene* scene) {
    double totalValue=0.0;
    double startAngle=0.0;

    double value=1;

    if(value > 0.0) {
        double angle=360*value/totalValue;
        scene->addEllipse(0,0,600,600);
        startAngle=startAngle+angle;
    }
}
