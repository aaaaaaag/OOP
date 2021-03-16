//
// Created by denis on 08.03.2021.
//

#ifndef LAB_01_OOP_ZOOMSHAPEUI_H
#define LAB_01_OOP_ZOOMSHAPEUI_H

#include <memory>
#include <QtWidgets/QLineEdit>
#include "QWidget"
#include "QVBoxLayout"
#include "ActionSlots.h"

class ZoomShapeUI: public QVBoxLayout {
public:

    explicit ZoomShapeUI(const std::shared_ptr<ActionSlots>& inActionSlots);

    QLineEdit* GetXLine();

    QLineEdit* GetYLine();

    QLineEdit* GetZLine();

private:

    QLineEdit *m_pXZoomLine;
    QLineEdit *m_pYZoomLine;
    QLineEdit *m_pZZoomLine;
};


#endif //LAB_01_OOP_ZOOMSHAPEUI_H
