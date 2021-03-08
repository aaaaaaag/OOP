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
#include "Qt/MoveShapeUI.h"
#include "Qt/RotateShapeUI.h"
#include "Qt/ZoomShapeUI.h"


MainMenu::MainMenu(const std::shared_ptr<ActionSlots>& inActionSlots) {

    resize(1200, 800);

    auto mainHBox = new QHBoxLayout;
    auto menuVBox = new QVBoxLayout;

    auto MoveUIPart = new MoveShapeUI(inActionSlots);
    auto RotateUIPart = new RotateShapeUI(inActionSlots);
    auto ZoomUIPart = new ZoomShapeUI(inActionSlots);

    menuVBox->addLayout(MoveUIPart);
    menuVBox->addLayout(RotateUIPart);
    menuVBox->addLayout(ZoomUIPart);

    //mainHBox->addWidget();
    //mainHBox->addWidget(PaintWidget);
    setLayout(menuVBox);
}
