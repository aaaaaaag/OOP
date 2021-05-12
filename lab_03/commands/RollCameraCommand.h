#ifndef ROLL_CAMERA_COMMAND_H
#define ROLL_CAMERA_COMMAND_H

#include "BaseCommand.h"
#include "../math/Point.h"
#include "../intermediary/Intermediary.h"

namespace commands {

class RollCameraCommand: public BaseCommand {
public:
    RollCameraCommand(std::string objectName, double angle);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_objectName;
    math::Point m_rotationData;
};

} // namespace commands

#endif // ROLL_CAMERA_COMMAND_H
