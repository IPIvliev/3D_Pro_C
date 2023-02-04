QT       += core gui

QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutwindow.cpp \
    accountprintwindow.cpp \
    advwindow.cpp \
    chooseprintwindow.cpp \
    dialog_default_window.cpp \
    firmwarewindow.cpp \
    loginwindow.cpp \
    main.cpp \
    main_window.cpp \
    printingwindow.cpp \
    servicewindow.cpp \
    settingwindow.cpp \
    usbprintwindow.cpp \
    vatwindow.cpp \
    wifiwindow.cpp \
    zwindow.cpp

HEADERS += \
    aboutwindow.h \
    accountprintwindow.h \
    advwindow.h \
    chooseprintwindow.h \
    dialog_default_window.h \
    firmwarewindow.h \
    loginwindow.h \
    main_window.h \
    printingwindow.h \
    servicewindow.h \
    settingwindow.h \
    usbprintwindow.h \
    vatwindow.h \
    wifiwindow.h \
    zwindow.h

FORMS += \
    about_window.ui \
    account_print_window.ui \
    adv_window.ui \
    choose_print_window.ui \
    dialog_default_window.ui \
    firmware_window.ui \
    login_window.ui \
    main_window.ui \
    printing_window.ui \
    service_window.ui \
    setting_window.ui \
    usb_print_window.ui \
    vat_window.ui \
    wifi_window.ui \
    z_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

include(modules/include.pri)

win32 {

LIBS += -lwininet

}
