#include <QtWidgets/QApplication>
#include "QMainWindow"
#include "Qt/MainMenu.h"
#include "Logic.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    UtilsStruct data;
    CanvasStruct canvasStruct{};
    initCanvas(canvasStruct);
    auto pActionSlots = std::make_shared<ActionSlots>(&data, canvasStruct);

    auto menu = new MainMenu(pActionSlots);
    menu->show();

    app.exec();
    ApplyAction(data, canvasStruct, choose::Quit);
    return 0;
}
