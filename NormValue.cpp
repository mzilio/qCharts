#include "NormValue.h"

NormValue::NormValue(QQueue<QPointF>* qPoint, QAbstractItemModel* model, int typeData) {
    int dim=500;
    if(typeData==0 || typeData==1) {
        double max=(model->data(model->index(0, typeData))).toDouble();
        for(int i=1; i<model->rowCount(); i++) {
            double value=(model->data(model->index(i, typeData))).toDouble();
            if(max<value)
                max=value;
        }
        for(int i=0; i<model->rowCount(); i++) {
            double value=(model->data(model->index(i, typeData))).toDouble();
            qPoint->enqueue(QPointF(dim*i/model->rowCount(), dim-(dim*value/max)));
        }
    }
    if(typeData==2) {
        double max0=(model->data(model->index(0, 0))).toDouble();
        double max1=(model->data(model->index(0, 1))).toDouble();
        for(int i=1; i<model->rowCount(); i++) {
            double value0=(model->data(model->index(i, 0))).toDouble();
            double value1=(model->data(model->index(i, 1))).toDouble();
            if(max0<value0)
                max0=value0;
            if(max1<value1)
                max1=value1;
        }
        for(int i=0; i<model->rowCount(); i++) {
            double value0=(model->data(model->index(i, 0))).toDouble();
            double value1=(model->data(model->index(i, 1))).toDouble();
            qPoint->enqueue(QPointF(dim*value0/max0, dim-(dim*value1/max1)));
        }
    }
}
