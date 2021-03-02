//
// Created by denis on 20.02.2021.
//

#include "Qt/BackButton.h"

#include <utility>



BackButton::BackButton(PaintHouse *painter) {
    m_pPainter = painter;
    setText("Back");
    connect(this, &QPushButton::clicked, this, &BackButton::MoveHouse);
}
void BackButton::MoveHouse() {
    m_pPainter->setPreviousHouse();
}