#pragma once

#include <QObject>

#include <constants.h>

enum doors_state {
    OPENING = 0,
    OPENED,
    CLOSING,
    CLOSED
};

class Doors : public QObject {
    Q_OBJECT

public:
    explicit Doors(QObject *parent = nullptr);

signals:
    void closedDoors();
    void openedDoors();

public slots:
    void startOpening();
    void startClosing();

private slots:
    void open();
    void close();

private:
    doors_state m_currentDoorsState;
    QTimer m_doorsOpenTimer;
    QTimer m_doorsCloseTimer;
    QTimer m_doorsStayOpenTimer;
};
