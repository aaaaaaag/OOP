#ifndef LAB4_RENDERCOMMAND_H
#define LAB4_RENDERCOMMAND_H

#include "BaseCommand.h"
#include "../intermediary/Intermediary.h"

namespace commands {

using intermediary::Intermediary;

class RenderCommand: public BaseCommand {
public:
    explicit RenderCommand(std::shared_ptr<render::BaseDrawer> drawer);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::shared_ptr<render::BaseDrawer> m_pDrawer;
};

} // namespace commands

#endif //LAB4_RENDERCOMMAND_H
