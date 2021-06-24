#pragma once

#include <utility>
#include <vector>

#include <objects/camera/camera.h>

class Composite;

class Scene{
public:
    Scene(): _objects(std::make_shared<Composite>()){};
    ~Scene() = default;

    void addObject(const std::shared_ptr<Object>& obj);
    void removeObject(const std::string& objName);
    std::shared_ptr<Object> getObject(const std::string& objName);
    std::shared_ptr<Composite> get_composite(){return _objects;};
    void accept(std::shared_ptr<BaseVisitor> visitor) {_objects->accept(std::move(visitor));};

private:
    void reform(const Point &move, const Point &scale, const Point &turn) {};
    std::shared_ptr<Composite> _objects;
};
