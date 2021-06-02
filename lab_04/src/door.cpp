#include <door.h>

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent), m_currentDoorsState(CLOSED) {
    m_doorsStayOpenTimer.setInterval(WAITING_TIME);
    m_doorsStayOpenTimer.setSingleShot(true);
    m_doorsOpenTimer.setSingleShot(true);
    m_doorsCloseTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(openedDoors()), &m_doorsStayOpenTimer,
                     SLOT(start()));
    QObject::connect(&m_doorsStayOpenTimer, SIGNAL(timeout()), this,
                     SLOT(closing()));
    QObject::connect(&m_doorsOpenTimer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&m_doorsCloseTimer, SIGNAL(timeout()), this, SLOT(close()));
}

void Doors::opening() {
    if (CLOSED != m_currentDoorsState && CLOSING != m_currentDoorsState)
        return;
    qDebug() << "Doors are opening........";
    if (m_currentDoorsState == CLOSED) {
        m_currentDoorsState = OPENING;
        m_doorsOpenTimer.start(DOORS_TIME);
    }
    else {
        m_currentDoorsState = OPENING;
        int t = m_doorsCloseTimer.remainingTime();
        m_doorsCloseTimer.stop();
        m_doorsOpenTimer.start(DOORS_TIME - t);
    }
}

void Doors::closing() { // change to closing
    if (OPENED != m_currentDoorsState)
        return;

    if (m_currentDoorsState == CLOSED) {
        emit closedDoors();
    }
    else {
        m_currentDoorsState = CLOSING;
        qDebug() << "Doors are closing.........";
        m_doorsCloseTimer.start(DOORS_TIME);
    }
}

void Doors::open() {
    if (m_currentDoorsState != OPENING)
        return;

    m_currentDoorsState = OPENED;
    qDebug() << "Doors are opened\nWaiting for passengers........";
    emit openedDoors();
}

void Doors::close() {
    if (m_currentDoorsState != CLOSING)
      return;

    m_currentDoorsState = CLOSED;
    qDebug() << "Doors are closed";
    emit closedDoors();
}
