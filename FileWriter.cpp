#include <QMessageBox>
#include <QDomDocument>
#include <QTextStream>
#include "FileWriter.h"

FileWriter::FileWriter(QString fileName, QAbstractItemModel* d, MyWidget* p) : file(fileName), model(d), parent(p) {
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(parent, tr("qCharts"), tr("Cannot read file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return;
    }
    QDomDocument doc;
    QDomElement root = doc.createElement("chart");
    doc.appendChild(root);
    QDomElement title = doc.createElement("title");
    root.appendChild(title);
    QDomText titleText = doc.createTextNode(parent->getTitle());
    title.appendChild(titleText);
    QDomElement xlabel = doc.createElement("xlabel");
    root.appendChild(xlabel);
    QDomText xText = doc.createTextNode(parent->getXLabel());
    xlabel.appendChild(xText);
    QDomElement ylabel = doc.createElement("ylabel");
    root.appendChild(ylabel);
    QDomText yText = doc.createTextNode(parent->getYLabel());
    ylabel.appendChild(yText);
    int row = model->rowCount();
    for(int i=0; i<row; i++) {
        QDomElement point = doc.createElement("point");
        root.appendChild(point);
        QDomElement x = doc.createElement("x");
        point.appendChild(x);
        QDomText xValue = doc.createTextNode((model->data(model->index(i, 0))).toString());
        x.appendChild(xValue);
        QDomElement y = doc.createElement("y");
        point.appendChild(y);
        QDomText yValue = doc.createTextNode((model->data(model->index(i, 1))).toString());
        y.appendChild(yValue);
    }
    QTextStream out(&file);
    out << doc.toString();
}
