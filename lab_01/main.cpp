#include <QtWidgets/QApplication>
#include "QMainWindow"
#include "Qt/MainMenu.h"
#include "Logic.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    utilData data;
    auto wid = new CanvasWidget;
    auto pActionSlots = std::make_shared<ActionSlots>(&data, wid);

    auto menu = new MainMenu(pActionSlots);
    menu->show();

    app.exec();
    ApplyAction(choose::Quit, data, wid);
    return 0;
}
