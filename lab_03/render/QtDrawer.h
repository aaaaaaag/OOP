#ifndef LAB4_QTDRAWER_H
#define LAB4_QTDRAWER_H

#include <QPainter>
#include <cmath>
#include "BaseDrawer.h"

namespace render {

class QtDrawer: public BaseDrawer {
public:
    explicit QtDrawer(QPainter *painter);
    void drawLine(const Point &p1, const Point &p2) override;
private:
    QPainter *m_pPainter;
};

} // namespace render

#endif //LAB4_QTDRAWER_H
