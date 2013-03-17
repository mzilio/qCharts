#ifndef NORMVALUE_H
#define NORMVALUE_H

#include <QAbstractItemModel>
#include <QQueue>
#include <QPointF>

class NormValue {

public:
    NormValue(QQueue<QPointF>*, QAbstractItemModel*, int);

};

#endif
