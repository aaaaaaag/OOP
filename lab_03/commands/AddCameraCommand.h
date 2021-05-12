#ifndef ADD_CAMERA_COMMAND_H
#define ADD_CAMERA_COMMAND_H

#include <string>
#include "BaseCommand.h"
#include "../intermediary/Intermediary.h"

namespace commands {

class AddCameraCommand: public BaseCommand {
public:
    explicit AddCameraCommand(std::string name);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_name;
};

} // namespace commands

#endif // ADD_CAMERA_COMMAND_H
