#ifndef YAW_CAMERA_COMMAND_H
#define YAW_CAMERA_COMMAND_H

#include "BaseCommand.h"
#include "../math/Point.h"
#include "../intermediary/Intermediary.h"

namespace commands {

class YawCameraCommand: public BaseCommand {
public:
    YawCameraCommand(std::string objectName, double angle);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_objectName;
    math::Point m_rotation;
};

} // namespace commands

#endif // YAW_CAMERA_COMMAND_H
