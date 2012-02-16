HEADERS += \
    ObjectManager.h \
    Editor.h \
    mainWindow.h

SOURCES += \
    editorMain.cpp \
    Editor.cpp \



QT += opengl

LIBS += -lSDL -lSDL_mixer -lGLU
