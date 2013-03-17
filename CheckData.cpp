#include <QAbstractItemModel>
#include <QMessageBox>
#include "CheckData.h"

CheckData::CheckData(QAbstractItemModel* model, int &type) {
    bool xString=false, yString=false;
    if(model) {
        for(int i=0; i<model->rowCount(); i++) {
            bool canConvert=false;
            (model->data(model->index(i, 0))).toDouble(&canConvert);
            if(!canConvert)
                xString=true;
            (model->data(model->index(i, 1))).toDouble(&canConvert);
            if(!canConvert)
                yString=true;
        }
        if(!xString && yString)
            type=0;
        else if(xString && !yString)
            type=1;
        else if(!xString && !yString)
            type=2;
        else
            type=-1;
    }
}
