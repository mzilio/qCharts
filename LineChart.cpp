#include <QPainter>
#include <QQueue>
#include <QPointF>
#include "LineChart.h"

LineChart::LineChart(QPainter &p, QQueue<QPointF>* queue) {
    p.setPen(QColor(Qt::black));
    p.drawLine(QPoint(0,0), QPoint(0,500));
    p.drawLine(QPoint(0,500), QPoint(500,500));
    for(int i=0; i<(queue->size())-1; i++) {
        p.setPen(QColor(Qt::blue));
        p.drawLine(queue->value(i), queue->value(i+1));
    }
    queue->clear();
}
