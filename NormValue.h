#ifndef NORMVALUE_H
#define NORMVALUE_H

#include <QAbstractItemModel>
#include <QQueue>
#include <QPointF>

class NormValue {

public:
    NormValue(QQueue<double>*, QQueue<QPointF>*, QAbstractItemModel*, int);

};

#endif
