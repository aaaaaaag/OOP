#include "DrawLabel.h"


DrawLabel::DrawLabel(QPixmap &pixmap): m_pPixmap(&pixmap)
{
    this->setPixmap(pixmap);
}

void DrawLabel::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0, 0), *m_pPixmap);
    painter.end();
}
