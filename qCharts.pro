TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

HEADERS += MyWidget.h FileReader.h \
    FileWriter.h \
    MyCanvas.h \
    CheckData.h \
    NormValue.h

SOURCES += main.cpp MyWidget.cpp FileReader.cpp \
    FileWriter.cpp \
    MyCanvas.cpp \
    CheckData.cpp \
    NormValue.cpp

TRANSLATIONS = lang/qCharts_it.ts

QT += xml xmlpatterns
