#include "Point.h"
#include "Matrix.h"


namespace math {

Point::Point(): m_x(0), m_y(0), m_z(0) {}

Point::Point(double x, double y, double z): m_x(x), m_y(y), m_z(z) {}

double Point::x() const {
    return m_x;
}

double Point::y() const {
    return m_y;
}

double Point::z() const {
    return m_z;
}

void Point::setX(double x) {
    m_x = x;
}

void Point::setY(double y) {
    m_y = y;
}

void Point::setZ(double z) {
    m_z = z;
}

void Point::transform(const std::shared_ptr<Matrix>& matrix) {
    std::vector<double> result(4);
    std::vector<double> data = {m_x, m_y, m_z, 1.};
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            result[i] += data[j] * matrix->get(i, j);
        }
    }

    *this = {result[0], result[1], result[2]};
}

} // namespace math
