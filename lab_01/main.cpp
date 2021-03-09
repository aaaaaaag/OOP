#include <iostream>
#include <QtWidgets/QApplication>
#include "DotFileIO.h"
#include "QMainWindow"
#include "Qt/MainMenu.h"

int main(int argc, char *argv[]) {

    int error = -1;
    auto res = GetDotsFromFile(argv[1], error);
//    for (int i = 0; i < res.coordsNumb; i++)
//    {
//        auto dot = res.shapeCoords[i];
//        std::cout << "Dot coords" << std::endl;
//        std::cout << "X: " << dot.coords.coordX << std::endl;
//        std::cout << "Y: " << dot.coords.coordY << std::endl;
//        std::cout << "Z: " << dot.coords.coordZ << std::endl;
//        std::cout << "Links" << std::endl;
//        for (int j = 0; j < dot.linksNumb; j++)
//        {
//            std::cout << dot.linkNodesNumbers[j] << std::endl;
//        }
//    }




    QApplication app(argc, argv);

    mainShape_t shape;
    utilData data;
    auto wid = new QWidget;

    auto pActionSlots = std::make_shared<ActionSlots>(shape, data, wid);

    auto menu = new MainMenu(pActionSlots);
    menu->show();

    return app.exec();
}
