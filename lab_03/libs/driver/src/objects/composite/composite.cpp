#include <objects/composite/composite.h>

Composite::Composite(std::shared_ptr<Object> &component) {
    objects.push_back(component);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector) {
    objects = vector;
}

bool Composite::add(const std::shared_ptr<Object> &component) {
    objects.push_back(component);
    return true;
}

bool Composite::remove(const Iterator &iterator) {
    objects.erase(iterator);
    return true;
}

Iterator Composite::begin() {
    return objects.begin();
}

Iterator Composite::end() {
    return objects.end();
}

bool Composite::is_visible() {
    return false;
}

bool Composite::is_composite() const {
    return true;
}

size_t Composite::size() const {
    return objects.size();
}

void Composite::reform(const Point &move, const Point &scale, const Point &turn) {
    for (const auto &elem : objects) {
        elem->reform(move, scale, turn);
    }
}

void Composite::accept(std::shared_ptr<BaseVisitor> visitor) {
    for (const auto &obj : objects) {
        obj->accept(visitor);
    }
}

std::vector<std::shared_ptr<Object>> &Composite::get_objects() { return objects; }

std::shared_ptr<ModelDetails> Composite::get_details() const {
    return std::shared_ptr<ModelDetails>();
}

Point Composite::get_pos() {
    return Point();
}

