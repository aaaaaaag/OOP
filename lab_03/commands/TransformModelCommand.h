#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "BaseCommand.h"
#include "../math/Point.h"
#include "../intermediary/Intermediary.h"

namespace commands {

using intermediary::Intermediary;
using math::Point;

class TransformModelCommand: public BaseCommand {
public:
    TransformModelCommand(std::string objectName, Point move, Point scale, Point rotate);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string m_objectName;
    Point m_moveCoords;
    Point m_scaleCoords;
    Point m_rotateCoords;
};

} // namespace commands

#endif // MOVE_COMMAND_H
