#include "Camera.h"

#include <utility>

namespace objects {

Camera::Camera(std::string name): Object(std::move(name)), m_xAngle(0), m_yAngle(0), m_zAngle(0) {
    m_position = math::Point(0, 0, 300);
}

const math::Point &Camera::getPosition() const {
    return m_position;
}
void Camera::setPosition(const math::Point &position) {
    Camera::m_position = position;
}

double Camera::getXAngle() const {
    return m_xAngle;
}
void Camera::setXAngle(double xAngle) {
    Camera::m_xAngle = xAngle;
}
double Camera::getYAngle() const {
    return m_yAngle;
}
void Camera::setYAngle(double yAngle) {
    Camera::m_yAngle = yAngle;
}
double Camera::getZAngle() const {
    return m_zAngle;
}
void Camera::setZAngle(double zAngle) {
    Camera::m_zAngle = zAngle;
}

void Camera::transform(const std::shared_ptr<math::Matrix> matrix) {
    m_position.transform(matrix);
}

void Camera::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}

} // namespace objects
