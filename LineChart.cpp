#include <QQueue>
#include <QPointF>
#include <QGraphicsScene>
#include "LineChart.h"

LineChart::LineChart(QQueue<QPointF>* queue, QGraphicsScene* scene) {
    for(int i=0; i<(queue->size())-1; i++) {
        scene->addLine((queue->value(i)).x(), (queue->value(i)).y(), (queue->value(i+1)).x(), (queue->value(i+1)).y());
    }
    scene->addText("Title");
    //TODO scene->addText("X Label");
    //scene->addText("Y Label");
}
