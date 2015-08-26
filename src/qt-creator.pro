HEADERS += \
    wcmFilter.h \
    wcmTouchFilter.h \
    xf86Wacom.h \
    xf86WacomDefs.h \
    ../include/isdv4.h \
    ../include/wacom-properties.h \
    ../include/wacom-util.h \
    ../include/Xwacom.h \
    wcmDistortion.h

SOURCES += \
    wcmCommon.c \
    wcmConfig.c \
    wcmFilter.c \
    wcmISDV4.c \
    wcmTouchFilter.c \
    wcmUSB.c \
    wcmValidateDevice.c \
    wcmXCommand.c \
    xf86Wacom.c \
    wcmDistortion.c

INCLUDEPATH += "../include" \
    "/usr/include/xorg/"
