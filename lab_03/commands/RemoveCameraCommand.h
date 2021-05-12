#ifndef REMOVE_CAMERA_COMMAND_H
#define REMOVE_CAMERA_COMMAND_H

#include "BaseCommand.h"
#include "../intermediary/Intermediary.h"

namespace commands {

class RemoveCameraCommand: public BaseCommand {
public:
    RemoveCameraCommand(std::string objectName);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_objectName;
};

} // namespace commands

#endif // REMOVE_CAMERA_COMMAND_H
