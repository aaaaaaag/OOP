#ifndef SET_CAMERA_H
#define SET_CAMERA_H

#include <string>
#include "BaseCommand.h"
#include "../intermediary/Intermediary.h"

namespace commands {

class SetCameraCommand: public BaseCommand {
public:
    explicit SetCameraCommand(std::string name);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_name;
};

} // namespac commands

#endif // SET_CAMERA_H
