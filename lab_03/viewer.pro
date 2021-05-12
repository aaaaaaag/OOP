#-------------------------------------------------
#
# Project created by QtCreator 2019-05-19T00:24:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = viewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        commands/AddCameraCommand.cpp \
        commands/AddModelCommand.cpp \
        commands/MoveCameraCommand.cpp \
        commands/PitchCameraCommand.cpp \
        commands/RemoveCameraCommand.cpp \
        commands/RemoveModelCommand.cpp \
        commands/RenderCommand.cpp \
        commands/RollCameraCommand.cpp \
        commands/SetCamera.cpp \
        commands/TransformModelCommand.cpp \
        commands/YawCameraCommand.cpp \
        DrawLabel.cpp \
        facade/ViewerFacade.cpp \
        intermediary/Intermediary.cpp \
        main.cpp \
        math/Matrix.cpp \
        math/Point.cpp \
        math/TransformMatrix.cpp \
        objects/Camera.cpp \
        objects/Composite.cpp \
        objects/Mesh.cpp \
        objects/Model.cpp \
        render/QtDrawer.cpp \
        render/Renderer.cpp \
        scene/Scene.cpp \
        scene/SceneManager.cpp \
        transformations/CameraManager.cpp \
        transformations/Transformer.cpp \
        uploading/FileLoader.cpp \
        uploading/ModelBuilder.cpp \
        uploading/ModelLoader.cpp \
    MainWindow.cpp

HEADERS += \
        BaseManager.h \
        commands/AddCameraCommand.h \
        commands/AddModelCommand.h \
        commands/BaseCommand.h \
        commands/MoveCameraCommand.h \
        commands/PitchCameraCommand.h \
        commands/RemoveCameraCommand.h \
        commands/RemoveModelCommand.h \
        commands/RenderCommand.h \
        commands/RollCameraCommand.h \
        commands/SetCamera.h \
        commands/TransformModelCommand.h \
        commands/YawCameraCommand.h \
        DrawLabel.h \
        exceptions/BaseViewerExeption.h \
        exceptions/CameraLackException.h \
        exceptions/DrawerException.h \
        exceptions/FileOpenException.h \
        exceptions/ModelBuildException.h \
        exceptions/ObjectSearchException.h \
        exceptions/ObjectTypeException.h \
        facade/ViewerFacade.h \
        intermediary/Intermediary.h \
        math/Matrix.h \
        math/Point.h \
        math/TransformMatrix.h \
        objects/Camera.h \
        objects/Composite.h \
        objects/Mesh.h \
        objects/Model.h \
        objects/Object.h \
        render/BaseDrawer.h \
        render/QtDrawer.h \
        render/Renderer.h \
        scene/Scene.h \
        scene/SceneManager.h \
        transformations/CameraManager.h \
        transformations/Transformer.h \
        uploading/AbsModelLoader.h \
        uploading/BaseLoaderImp.h \
        uploading/FileLoader.h \
        uploading/ModelBuilder.h \
        uploading/ModelLoader.h \
        visitor/Visitor.h \
    MainWindow.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
