#ifndef ADD_MODEL_COMMAND_H
#define ADD_MODEL_COMMAND_H

#include <string>
#include "BaseCommand.h"
#include "../intermediary/Intermediary.h"

namespace commands {

using intermediary::Intermediary;

class AddModelCommand: public BaseCommand {
public:
    explicit AddModelCommand(std::string filename, std::string modelName);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_fileName;
    std::string m_modelName;
};

} // namespace commands

#endif // ADD_MODEL_COMMAND_H
