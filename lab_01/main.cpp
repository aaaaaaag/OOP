#include <iostream>
#include <QtWidgets/QApplication>
#include "DotFileIO.h"
#include "QMainWindow"
#include "Qt/MainMenu.h"

int main(int argc, char *argv[]) {


    int error = -1;
    auto res = GetDotsFromFile(argv[1], error);
    QApplication app(argc, argv);

    mainShape_t shape;
    utilData data;
    auto wid = new QWidget;

    auto pActionSlots = std::make_shared<ActionSlots>(shape, data, wid);

    auto menu = new MainMenu(pActionSlots);
    menu->show();

    return app.exec();
}
