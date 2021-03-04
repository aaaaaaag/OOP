//
// Created by denis on 20.02.2021.
//

#include <QtWidgets/QFormLayout>
#include "Qt/MainMenu.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "Qt/MoveButton.h"
#include "Qt/RotateButton.h"
#include "Qt/ZoomButton.h"
#include "Qt/PaintHouse.h"
#include "Qt/BackButton.h"



MainMenu::MainMenu() {

    resize(1200, 800);

    auto mainHBox = new QHBoxLayout;
    auto menuVBox = new QVBoxLayout;

    auto PaintWidget = new PaintHouse(inHouse, this);

    auto xMoveLine = new QLineEdit;
    auto yMoveLine = new QLineEdit;

    auto *formX = new QFormLayout();
    auto *formY = new QFormLayout();
    formX->addRow("X: ", xMoveLine);
    formY->addRow("Y: ", yMoveLine);

    auto moveHouseButton = new MoveButton(inHouse, xMoveLine, yMoveLine, PaintWidget);


    auto degreesLine = new QLineEdit;
    auto *formDegrees = new QFormLayout();
    formDegrees->addRow("Degrees: ", degreesLine);

    auto xRotateCenterLine = new QLineEdit;
    auto yRotateCenterLine = new QLineEdit;
    auto *formCenterX = new QFormLayout();
    auto *formCenterY = new QFormLayout();
    formCenterX->addRow("Сenter X: ", xRotateCenterLine);
    formCenterY->addRow("Сenter Y: ", yRotateCenterLine);

    auto rotateHouseButton = new RotateButton(inHouse, degreesLine, xRotateCenterLine, yRotateCenterLine, PaintWidget, this);



    auto zoomLineX = new QLineEdit;
    auto zoomLineY = new QLineEdit;
    auto *formZoomX = new QFormLayout();
    auto *formZoomY = new QFormLayout();
    formZoomX->addRow("Zoom x: ", zoomLineX);
    formZoomY->addRow("Zoom y: ", zoomLineY);
    auto zoomHouseButton = new ZoomButton(inHouse, zoomLineX, zoomLineY, xRotateCenterLine, yRotateCenterLine, PaintWidget);


    auto back = new BackButton(PaintWidget);


    menuVBox->addLayout(formX);
    menuVBox->addLayout(formY);
    menuVBox->addWidget(moveHouseButton);

    menuVBox->addLayout(formCenterX);
    menuVBox->addLayout(formCenterY);
    menuVBox->addLayout(formDegrees);
    menuVBox->addWidget(rotateHouseButton);

    menuVBox->addLayout(formZoomX);
    menuVBox->addLayout(formZoomY);
    menuVBox->addWidget(zoomHouseButton);
    menuVBox->addWidget(back);

    mainHBox->setSpacing(2);
    mainHBox->setStretch(2, 2);

    auto test = new QWidget;
    test->setLayout(menuVBox);
    test->show();
    test->setMaximumSize(MAX_MENU_WIDE, MAX_MENU_HEIGHT);
    test->setMinimumSize(MAX_MENU_WIDE, MAX_MENU_HEIGHT);

    mainHBox->addWidget(test);
    mainHBox->addWidget(PaintWidget);
    setLayout(mainHBox);
}
