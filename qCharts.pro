TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

HEADERS += MyWidget.h FileReader.h \
    FileWriter.h

SOURCES += main.cpp MyWidget.cpp FileReader.cpp \
    FileWriter.cpp

TRANSLATIONS = qCharts_it.ts

QT += xml xmlpatterns
