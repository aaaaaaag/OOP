#include "Renderer.h"

#include <utility>

namespace render {

void Renderer::setDrawer(std::shared_ptr<BaseDrawer> drawer) {
    m_pDrawer = std::move(drawer);
}

void Renderer::setCamera(std::shared_ptr<Camera> camera) {
    m_pCamera = std::move(camera);
}

void Renderer::visit(Model &model) {
    if (!m_pDrawer || !m_pCamera)
        throw exceptions::DrawerInitException("Drawer or camera wasn't set");

    auto mesh = model.getMesh();
    auto lines = mesh->getLines();
    for (auto &line: lines) {
        projectPoint(line.first);
        projectPoint(line.second);
        m_pDrawer->drawLine(line.first, line.second);
    }
}

void Renderer::visit(Composite&) {}

void Renderer::visit(Camera&) {}

void Renderer::projectPoint(math::Point &point) {
    auto cameraPosition = m_pCamera->getPosition();
    std::shared_ptr<Matrix> transformMatrix(new MoveMatrix(static_cast<int>(-cameraPosition.x()),
                                                           static_cast<int>(-cameraPosition.y()),
                                                           0));
    point.transform(transformMatrix);
    transformMatrix.reset(new RotateOxMatrix(-m_pCamera->getXAngle()));
    point.transform(transformMatrix);
    transformMatrix.reset(new RotateOyMatrix(-m_pCamera->getYAngle()));
    point.transform(transformMatrix);
    transformMatrix.reset(new RotateOzMatrix(-m_pCamera->getZAngle()));
    point.transform(transformMatrix);

    double eps = 1e-10;
    double znam = point.z() + cameraPosition.z();
    if (znam < eps && znam > -eps) {
        znam = eps;
    }
    double distCoef = cameraPosition.z() / znam;
    point.setX(point.x() * distCoef);
    point.setY(point.y() * distCoef);
}

} // namespace render
