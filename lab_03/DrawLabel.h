#ifndef DRAWLABEL_H
#define DRAWLABEL_H

#include <QObject>
#include <QLabel>
#include <QPainter>

class DrawLabel : public QLabel
{
    Q_OBJECT

public:
    explicit DrawLabel(QPixmap & pixmap);
    void paintEvent(QPaintEvent * e) override;

private:
    QPixmap * m_pPixmap;
};

#endif // DRAWLABEL_H
