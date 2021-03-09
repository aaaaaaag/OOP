//
// Created by denis on 20.02.2021.
//

#ifndef LAB_01_ZOOMBUTTON_H
#define LAB_01_ZOOMBUTTON_H

#include "QPushButton"
#include "QLineEdit"
#include "ActionSlots.h"
#include "ZoomShapeUI.h"

class ZoomButton: public QPushButton {
public:

    ZoomButton(std::shared_ptr<ActionSlots> inActionSlots, ZoomShapeUI* inShape);

private:
    void UpdateUtilData();

    std::shared_ptr<ActionSlots> m_pActionSlots;
    ZoomShapeUI *m_pShapeUI;

};


#endif //LAB_01_ZOOMBUTTON_H
