//
// Created by denis on 20.02.2021.
//

#include "Qt/MainMenu.h"
#include "QHBoxLayout"
#include "Qt/MoveButton.h"
#include "Qt/MoveShapeUI.h"
#include "Qt/RotateShapeUI.h"
#include "Qt/ZoomShapeUI.h"
#include "Qt/LoadFileButton.h"

MainMenu::MainMenu(const std::shared_ptr<ActionSlots>& inActionSlots) {

    resize(1200, 800);
    auto mainHBox = new QHBoxLayout;
    auto menuVBox = new QVBoxLayout;

    auto loadButton = new LoadFileButton(inActionSlots);
    auto MoveUIPart = new MoveShapeUI(inActionSlots);
    auto RotateUIPart = new RotateShapeUI(inActionSlots);
    auto ZoomUIPart = new ZoomShapeUI(inActionSlots);

    menuVBox->addWidget(loadButton);
    menuVBox->addLayout(MoveUIPart);
    menuVBox->addLayout(RotateUIPart);
    menuVBox->addLayout(ZoomUIPart);

    mainHBox->addLayout(menuVBox);
    mainHBox->addWidget(inActionSlots->GetCanvas());

    setLayout(mainHBox);
}
