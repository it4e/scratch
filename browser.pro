QT += webengine
QT += webenginewidgets
QT += widgets

CONFIG += staticlib

SOURCES += \
    main.cpp \
    browser.cpp \
    browserheader.cpp \
    browserpage.cpp \
    tabs.cpp \
    jsinterface.cpp \
    browsersettings.cpp

HEADERS += \
    browser.h \
    browserheader.h \
    browserpage.h \
    jsinterface.h \
    tabs.h \
    browsersettings.h

DISTFILES += \
    header.js \
    header.html
