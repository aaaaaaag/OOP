#include "Composite.h"

namespace objects {

void Composite::add(const std::shared_ptr<Object>& object) {
    m_vObjects.push_back(object);
}

void Composite::remove(size_t ind) {
    auto iterator = m_vObjects.begin();
    std::advance(iterator, ind); // TODO wtf advance
    m_vObjects.erase(iterator);
}

std::vector<std::shared_ptr<Object> > Composite::getObjects() {
    return m_vObjects;
}

void Composite::transform(const std::shared_ptr<math::Matrix> matrix) {
    for (auto &object: m_vObjects)
        object->transform(matrix);
}

void Composite::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
    for (auto &obj: m_vObjects)
        obj->accept(visitor);
}

ssize_t Composite::getIndex(const std::shared_ptr<Object>& obj) {
    for (size_t i = 0; i < m_vObjects.size(); i++) {
        if (obj == m_vObjects[i])
            return i;
    }

    return -1;
}

} // namespace objects


