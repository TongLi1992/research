QT += core
QT -= gui
INCLUDEPATH += qtlibbw
CONFIG += c++11

TARGET = bwtest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

include(qtlibbw/bosswave.pri)
