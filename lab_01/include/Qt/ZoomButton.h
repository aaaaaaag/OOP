//
// Created by denis on 20.02.2021.
//

#ifndef LAB_01_ZOOMBUTTON_H
#define LAB_01_ZOOMBUTTON_H

#include "QPushButton"
#include "QLineEdit"
#include "MyHouse.h"
#include "PaintHouse.h"

class ZoomButton: public QPushButton {
public:

    ZoomButton(std::shared_ptr<MyHouse> inHouse, QLineEdit *editLineX,
               QLineEdit *editLineY, QLineEdit *xZoomCenter,
               QLineEdit *yZoomCenter, PaintHouse *painter);

private slots:

    void ZoomHouse();

private:

    QLineEdit *m_pXCenter;
    QLineEdit *m_pYCenter;
    PaintHouse *m_pPainter;
    std::shared_ptr<MyHouse> m_pHouse;
    QLineEdit *m_pLineZoomX;
    QLineEdit *m_pLineZoomY;
};


#endif //LAB_01_ZOOMBUTTON_H
