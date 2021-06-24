#include <scene/scene.h>

#include <iterator>

void Scene::addObject(const std::shared_ptr<Object>& obj) {
    _objects->add(obj);
}

void Scene::removeObject(const std::string& objName) {
    for (auto iter = _objects->begin(); iter != _objects->end(); iter++)
    {
        if (iter->get()->getName() == objName)
            _objects->remove(iter);
    }
}

std::shared_ptr<Object> Scene::getObject(const std::string &objName) {
    for (auto iter = _objects->begin(); iter != _objects->end(); iter++)
    {
        if (iter->get()->getName() == objName)
            return *iter;
    }
}
