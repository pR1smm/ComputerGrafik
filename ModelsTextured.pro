#-------------------------------------------------
#
# Project created by QtCreator 2011-03-04T17:34:20
#
#-------------------------------------------------




QT       += gui core widgets opengl multimedia
TARGET = ModelsTextured
TEMPLATE = app
CONFIG += c++11

win32 {
    CONFIG += console #Notwendig in 5.5, da sonst qMain gesucht wird und nicht gefunden wird... eher ein Bug in Qt5.5?
    LIBS += -lopengl32
}

macx {
    QMAKE_MAC_SDK = macosx10.11
}

#Um GL ES3 Header zu finden
android {
    message("* Using settings for Android.")
    message($$ANDROID_PLATFORM_PATH)
    INCLUDEPATH += /Users/bdr1/AndroidDev/android-ndk-r11c/platforms/android-23/arch-arm/usr/include #$$ANDROID_PLATFORM_PATH/include
}


#//nicht vergessen das anzupassen
SGFRAMEWORKINCLUDEPATH = "../SGFrameworkLib"
SGFRAMEWORKPATH = $${SGFRAMEWORKINCLUDEPATH}
PRE_TARGETDEPS += $${SGFRAMEWORKPATH}/libSGFramework.a
INCLUDEPATH += $${SGFRAMEWORKINCLUDEPATH}

LIBS += $${SGFRAMEWORKPATH}/libSGFramework.a
DEFINES += SRCDIR=\\\"$${_PRO_FILE_PWD_}\\\"

SOURCES += \
    mainscene.cpp \
    #myscene.cpp
    cslime.cpp \
    SlimeTicker.cpp \
    level.cpp \
    trycallback.cpp

OTHER_FILES += \
    ../../Data/Shader/brick1.frag \
    ../../Data/Shader/brick.vert \
    ../../Data/Shader/toon.vert \
    ../../Data/Shader/toon.frag \
    ../../Data/Shader/PhongVL_Half.vert \
    ../../Data/Shader/PhongFragment.vert \
    ../../Data/Shader/PhongFragment.frag \
    ../../Data/Shader/hello_glsl.vert \
    ../../Data/Shader/hello_glsl.frag \
    ../../Data/Shader/cloud.vert \
    ../../Data/Shader/cloud.frag

RESOURCES += \
    MyShaders.qrc

HEADERS += \
    mainscene.h \
    cslime.h \
    SlimeTicker.h \
    level.h \
    trycallback.h
