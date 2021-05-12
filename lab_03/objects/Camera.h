#ifndef CAMERA_H
#define CAMERA_H

#include "Object.h"
#include "../math/Point.h"

namespace objects {

class Camera: public Object {
public:
    explicit Camera(std::string name);

    [[nodiscard]] const math::Point &getPosition() const;
    void setPosition(const math::Point &position);
    [[nodiscard]] double getXAngle() const;
    void setXAngle(double xAngle);
    [[nodiscard]] double getYAngle() const;
    void setYAngle(double yAngle);
    [[nodiscard]] double getZAngle() const;
    void setZAngle(double zAngle);

    void transform(std::shared_ptr<Matrix> matrix) override;
    void accept(std::shared_ptr<Visitor> visitor) override;
private:
    math::Point m_position;
    double m_xAngle;
    double m_yAngle;
    double m_zAngle;
};

} // namespace objects

#endif // CAMERA_H
