#ifndef VIEWER_FACADE_H
#define VIEWER_FACADE_H

#include "../intermediary/Intermediary.h"
#include "../commands/BaseCommand.h"

namespace facade {

using intermediary::Intermediary;
using commands::BaseCommand;

class ViewerFacade {
public:
    ViewerFacade();
    void execCommand(BaseCommand *command);
private:
    std::shared_ptr<Intermediary> m_pIntermediary;
};

} // namespace facade

#endif // VIEWER_FACADE_H
