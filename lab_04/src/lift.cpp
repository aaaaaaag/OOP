#include <lift.h>

Lift::Lift() {
    QObject::connect(&cabin, SIGNAL(cabinStopped(int)), this,
                     SLOT(reach(int)));
    QObject::connect(&control_panel, SIGNAL(setFloorTarget(int, direction)), &cabin,
                   SLOT(cabinCall(int, direction)));
    QObject::connect(&cabin, SIGNAL(cabinCrossingFloor(int, direction)),
                   &control_panel, SLOT(passedFloor(int)));
    QObject::connect(&cabin, SIGNAL(cabinStopped(int)), &control_panel,
                   SLOT(achievedFloor(int)));
}

void Lift::click(int floor) {
    control_panel.setNewFloorTarget(floor);
}

void Lift::reach(int floor) {
    emit liftReachedFloor(floor);
}
