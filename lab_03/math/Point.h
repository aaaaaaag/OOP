#ifndef POINT_H
#define POINT_H

#include <memory>
#include "Matrix.h"

namespace math {

class Point {
public:
    Point();
    Point(double x, double y, double z);

    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void transform(const std::shared_ptr<math::Matrix>& matrix);
private:
    double m_x;
    double m_y;
    double m_z;
};

} // namespace math

#endif // POINT_H
