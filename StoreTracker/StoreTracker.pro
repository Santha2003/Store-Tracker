QT       += core gui sql
QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    billing_form.cpp \
    companydata.cpp \
    companydetails.cpp \
    homepage.cpp \
    login.cpp \
    main.cpp \
    adminloginpage.cpp \
    product.cpp \
    purchase.cpp \
    purchase_voucher.cpp \
    sales.cpp \
    userlogin.cpp \
    voucher_update.cpp

HEADERS += \
    adminloginpage.h \
    adminpage.h \
    billing_form.h \
    companydata.h \
    companydetails.h \
    homepage.h \
    login.h \
    product.h \
    purchase.h \
    purchase_voucher.h \
    sales.h \
    userlogin.h \
    voucher_update.h

FORMS += \
    adminloginpage.ui \
    adminpage.ui \
    billing_form.ui \
    companydata.ui \
    companydetails.ui \
    homepage.ui \
    login.ui \
    product.ui \
    purchase.ui \
    purchase_voucher.ui \
    sales.ui \
    userlogin.ui \
    voucher_update.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
store.qrc
RC_ICONS=store.ico

