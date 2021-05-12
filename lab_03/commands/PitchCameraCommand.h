#ifndef PITCH_CAMERA_COMMAND_H
#define PITCH_CAMERA_COMMAND_H

#include "BaseCommand.h"
#include "../math/Point.h"
#include "../intermediary/Intermediary.h"

namespace commands {

class PitchCameraCommand: public BaseCommand {
public:
    PitchCameraCommand(std::string objectName, double angle);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_objectName;
    math::Point m_rotationData;
};

} // namespace commands

#endif // PITCH_CAMERA_COMMAND_H
