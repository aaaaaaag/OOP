#pragma once

#include <memory>

#include <drawer/abstract_drawer.h>
#include <managers/base_manager.h>
#include <objects/composite/composite.h>
#include <objects/model/details/point/point.h>
#include <DrawVisitor.h>
#include "scene/scene.h"
class Scene;
class DrawManager: public BaseManager {
public:
    DrawManager() = default;
    DrawManager(const DrawManager &) = delete;
    DrawManager &operator=(const DrawManager &) = delete;
    ~DrawManager() = default;

    void set_drawer(std::shared_ptr<AbstractDrawer>);
    void set_cam(std::shared_ptr<Object>);

    void draw(const std::shared_ptr<Scene>& inScene);

private:

    std::shared_ptr<DrawVisitor> _visitor;
    Point proect_point(const Point &point);
    std::shared_ptr<AbstractDrawer> _drawer;
    std::shared_ptr<Object> cam;
};
