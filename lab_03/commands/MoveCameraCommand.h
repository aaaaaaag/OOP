#ifndef MOVE_CAMERA_COMMAND_H
#define MOVE_CAMERA_COMMAND_H

#include "BaseCommand.h"
#include "../math/Point.h"
#include "../intermediary/Intermediary.h"

namespace commands {

using intermediary::Intermediary;
using math::Point;

class MoveCameraCommand: public BaseCommand {
public:
    MoveCameraCommand(std::string objectName, Point move);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_objectName;
    Point m_moveCoords;
};

} // namespace commands

#endif // MOVE_CAMERA_COMMAND_H
