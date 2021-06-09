#include <QDebug>
#include "../inc/doors.hpp"

doors::doors(QObject *parent) : QObject(parent)
{
    doors_stay_timer.setInterval(STAY_TIME);
    doors_stay_timer.setSingleShot(true);
    doors_open_timer.setSingleShot(true);
    doors_close_timer.setSingleShot(true);

    QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(closed()));
    QObject::connect(this, SIGNAL(doors_opened()), &doors_stay_timer, SLOT(start()));
    QObject::connect(&doors_stay_timer, SIGNAL(timeout()), this, SLOT(start_closing()));
}

void doors::start_opening()
{
    if (m_state != CLOSING && m_state != CLOSED)
        return;

    qDebug() << "Doors are opening...";
    if (m_state == CLOSED)
    {
        m_state = OPENING;
        doors_open_timer.start(DOORS_TIME);
    }
    else
    {
        m_state = OPENING;
        int t = doors_close_timer.remainingTime();
        doors_close_timer.stop();
        doors_open_timer.start(DOORS_TIME - t);
    }
}

void doors::start_closing()
{
    if (m_state != OPENED)
        return;

    m_state = CLOSING;
    qDebug() << "Doors are closing...";
    doors_close_timer.start(DOORS_TIME);
}

void doors::opened()
{
    if (m_state != OPENING)
        return;

    m_state = OPENED;
    qDebug() << "The doors are opened.";
    emit doors_opened();
}

void doors::closed()
{
    if (m_state != CLOSING)
        return;

    m_state = CLOSED;
    qDebug() << "The doors are closed.";
    emit doors_closed();
}
