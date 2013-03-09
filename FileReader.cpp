#include <QString>
#include <QByteArray>
#include <QXmlSchema>
#include <QXmlSchemaValidator>
#include <QMessageBox>
#include <QDomDocument>
#include <QDomNode>
#include "FileReader.h"

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
        if(validator.validate(&file, QUrl::fromLocalFile(file.fileName()))){
            isReadable=true;
        }
        else {
            isReadable=false;
            QMessageBox::warning(this, tr("qCharts"), tr("The file that you are trying to open isn't valid."));
        }
    }
    file.close();
}

bool FileReader::read() {
    if(isReadable) {
        file.open(QFile::ReadOnly | QFile::Text);
        QString errorStr;
        int errorLine;
        int errorColumn;

        QDomDocument doc;
        if(!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) {
            std::cerr << "Error: Parse error at line " << errorLine << ", " << "column " << errorColumn << ": " << qPrintable(errorStr) << std::endl;
            return false;
        }

        QDomElement root = doc.documentElement();
        parseDocument(root);
        return true;
    }
    else
        return false;
}

void FileReader::parseDocument(const QDomElement& element) {
    QDomNode child = element.firstChild();
    while(!child.isNull()) {
        if(child.toElement().tagName() == "title")
            readTitle(child.toElement());
        else if(child.toElement().tagName() == "xlabel")
            readXLabel(child.toElement());
        else if(child.toElement().tagName() == "ylabel")
            readYLabel(child.toElement());
        child = child.nextSibling();
    }
}

void FileReader::readTitle(const QDomElement& element) {
    parent->setTitle(element.text());
}

void FileReader::readXLabel(const QDomElement& element) {
    parent->setXLabel(element.text());
}

void FileReader::readYLabel(const QDomElement& element) {
    parent->setYLabel(element.text());
}
