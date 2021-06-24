#include <managers/draw/draw_manager.h>

#include <utility>

#include <objects/model/model.h>
#include <objects/camera/camera.h>

void DrawManager::set_drawer(std::shared_ptr<AbstractDrawer> drawer) {
    _drawer = std::move(drawer);
}

void DrawManager::set_cam(std::shared_ptr<Object> new_cam) {
    cam = std::move(new_cam);
}

Point DrawManager::proect_point(const Point &_point) {
    Point new_point(_point);
    Point cam_pos(cam->get_pos());
    new_point.set_x(new_point.get_x() + cam_pos.get_x());
    new_point.set_y(new_point.get_y() + cam_pos.get_y());

    return new_point;
}

void DrawManager::draw(const std::shared_ptr<Scene>& inScene) {
    _visitor = std::make_shared<DrawVisitor>(_drawer, cam);
    inScene->accept(_visitor);
}
