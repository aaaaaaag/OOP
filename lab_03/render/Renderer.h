#ifndef LAB4_RENDERER_H
#define LAB4_RENDERER_H

#include <memory>
#include "../BaseManager.h"
#include "BaseDrawer.h"
#include "../exceptions/DrawerException.h"
#include "../visitor/Visitor.h"
#include "../objects/Composite.h"
#include "../objects/Model.h"
#include "../objects/Camera.h"
#include "../math/Point.h"
#include "../math/TransformMatrix.h"

namespace render {

using namespace math;
using namespace objects;

class Renderer: public Visitor, public BaseManager {
public:
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void setCamera(std::shared_ptr<Camera> camera);
    void visit(Model &model) override;
    void visit(Composite &composite) override;
    void visit(Camera &camera) override;

private:
    std::shared_ptr<BaseDrawer> m_pDrawer;
    std::shared_ptr<Camera> m_pCamera;

    void projectPoint(Point &point);
};

} // namespace render;

#endif //LAB4_RENDERER_H
