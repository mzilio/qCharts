#include <QString>
#include <QByteArray>
#include <QXmlSchema>
#include <QXmlSchemaValidator>
#include <QMessageBox>
#include "FileReader.h"

#include <iostream>
using namespace std;

FileReader::FileReader(QString fileName, MyWidget* p) : file(fileName), parent(p) {
    QByteArray data("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
                    "<xsd:schema xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                    "<xsd:element name=\"chart\" type=\"chartType\"/>"
                    "	<xsd:complexType name=\"chartType\">"
                    "		<xsd:sequence>"
                    "			<xsd:element name=\"title\" type=\"xsd:string\"/>"
                    "			<xsd:element name=\"xlabel\" type=\"xsd:string\" minOccurs=\"0\"/>"
                    "			<xsd:element name=\"ylabel\" type=\"xsd:string\" minOccurs=\"0\"/>"
                    "			<xsd:element name=\"point\" type=\"pointType\" maxOccurs=\"unbounded\"/>"
                    "		</xsd:sequence>"
                    "	</xsd:complexType>"
                    "	<xsd:complexType name=\"pointType\">"
                    "		<xsd:sequence>"
                    "			<xsd:element name=\"x\" type=\"xsd:string\"/>"
                    "			<xsd:element name=\"y\" type=\"xsd:string\"/>"
                    "		</xsd:sequence>"
                    "	</xsd:complexType>"
                    "</xsd:schema>");
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(parent, tr("qCharts"), tr("Cannot read file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return;
    }
    QXmlSchema schema;
    schema.load(data);
    if(schema.isValid()) {
        QXmlSchemaValidator validator(schema);
        if (validator.validate(&file, QUrl::fromLocalFile(file.fileName()))){
            isReadable=true;
        }
        else {
            isReadable=false;
            QMessageBox::warning(this, tr("qCharts"), tr("The file that you are trying to open isn't valid."));
        }
    }
}

bool FileReader::read() {
    if(isReadable) {
        xin.setDevice(&file);
        cout << "FileReader::read()" << endl; //TODO togliere
        while (xin.readNextStartElement()) { //TODO capire come effettuare il parsing
            if (xin.name() == "title")
                readTitle();
            else if (xin.name() == "xlabel")
                readXLabel();
            else if (xin.name() == "ylabel")
                readYLabel();
            else
                xin.skipCurrentElement();
        }
    }
    return true;
}

void FileReader::readTitle() {
    QString title = xin.readElementText();
    parent->setTitle(title);
    cout << "FileReader::readTitle()" << endl; //TODO togliere
}

void FileReader::readXLabel() {

}

void FileReader::readYLabel() {

}
