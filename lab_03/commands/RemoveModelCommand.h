#ifndef REMOVE_OBJECT_COMMAND_H
#define REMOVE_OBJECT_COMMAND_H

#include "BaseCommand.h"
#include "../intermediary/Intermediary.h"

namespace commands {

class RemoveModelCommand: public BaseCommand {
public:
    RemoveModelCommand(std::string objectName);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_objectName;
};

} // namespace commands

#endif // REMOVE_OBJECT_COMMAND_H
