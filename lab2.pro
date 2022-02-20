TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CPlusPlusUnits.cpp \
        Units.cpp \
        main.cpp

HEADERS += \
    CPlusPlusCodeGenerator.h \
    CPlusPlusUnits.h \
    ICodeGenerator.h \
    Units.h
