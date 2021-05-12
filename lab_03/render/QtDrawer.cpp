#include "QtDrawer.h"

namespace render {

QtDrawer::QtDrawer(QPainter *painter): m_pPainter(painter) {}

void QtDrawer::drawLine(const math::Point &p1, const math::Point &p2) {
    auto w = m_pPainter->window().width() / 2;
    auto h = m_pPainter->window().height() / 2;
    m_pPainter->drawLine(w + std::round(p1.x()), h - std::round(p1.y()),
                       w + std::round(p2.x()), h - std::round(p2.y()));
}

} // namespace render
