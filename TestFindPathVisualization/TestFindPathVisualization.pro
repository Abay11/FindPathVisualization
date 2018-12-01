QT += testlib widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test.cpp \
 ../logicimpl.cpp \
 ../cell.cpp \

HEADERS += ../logicimpl.h \
 ../cell.h
