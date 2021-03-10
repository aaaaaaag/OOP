#include <iostream>
#include <QtWidgets/QApplication>
#include "DotFileIO.h"
#include "QMainWindow"
#include "Qt/MainMenu.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    mainShape_t shape;
    utilData data;

    auto wid = new CanvasWidget;
    auto pActionSlots = std::make_shared<ActionSlots>(shape, data, wid);

    auto menu = new MainMenu(pActionSlots);
    menu->show();

    app.exec();

    freeAll(shape);
    return 0;
}
