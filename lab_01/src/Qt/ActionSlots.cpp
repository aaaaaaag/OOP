//
// Created by denis on 08.03.2021.
//

#include "Qt/ActionSlots.h"
#include "Logic.h"

ActionSlots::ActionSlots(mainShape_t &shape, utilData &data, QWidget *paint): m_shape(&shape), m_data(&data), m_pPaint(paint) {
}

void ActionSlots::Move() {
    ApplyAction(choose::MoveShape, *m_shape, *m_data);
    m_pPaint->repaint();
}

void ActionSlots::Rotate() {
    ApplyAction(choose::RotateShape, *m_shape, *m_data);
    m_pPaint->repaint();
}

void ActionSlots::Scale() {
    ApplyAction(choose::RotateShape, *m_shape, *m_data);
    m_pPaint->repaint();
}

utilData *ActionSlots::GetUtilData() {
    return m_data;
}

void ActionSlots::SetUtilsData(utilData *inData) {
    m_data = inData;
}
