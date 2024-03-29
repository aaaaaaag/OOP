#include <objects/camera/camera.h>

void Camera::move_x(const double &shift) {
    current_pos.set_x(current_pos.get_x() + shift);
}

void Camera::move_y(const double &shift) {
    current_pos.set_y(current_pos.get_y() + shift);
}

void Camera::move_z(const double &shift) {
    current_pos.set_z(current_pos.get_z() + shift);
}

void Camera::reform(const Point &new_pos, const Point &scale, const Point &turn) {
    move_x(new_pos.get_x());
    move_y(new_pos.get_y());
}

void Camera::accept(std::shared_ptr<BaseVisitor> _visitor) {
    _visitor->visit(*this);
}

std::shared_ptr<ModelDetails> Camera::get_details() const {
    return std::shared_ptr<ModelDetails>();
}

std::vector<std::shared_ptr<Object>> &Camera::get_objects() {
    std::vector<std::shared_ptr<Object>> c;
    return c;
}
