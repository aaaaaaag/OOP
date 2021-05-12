#include "TransformMatrix.h"

namespace math {

MoveMatrix::MoveMatrix(int x, int y, int z) {
    m_vData[0][0] = 1;
    m_vData[1][1] = 1;
    m_vData[2][2] = 1;
    m_vData[3][3] = 1;
    m_vData[0][3] = x;
    m_vData[1][3] = y;
    m_vData[2][3] = z;
}

ScaleMatrix::ScaleMatrix(double x, double y, double z) {
    m_vData[0][0] = x;
    m_vData[1][1] = y;
    m_vData[2][2] = z;
    m_vData[3][3] = 1;
}

RotateOxMatrix::RotateOxMatrix(double angle) {
    m_vData[0][0] = 1;
    m_vData[1][1] = cos(angle);
    m_vData[1][2] = -sin(angle);
    m_vData[2][1] = sin(angle);
    m_vData[2][2] = cos(angle);
    m_vData[3][3] = 1;
}

RotateOyMatrix::RotateOyMatrix(double angle) {
    m_vData[0][0] = cos(angle);
    m_vData[1][1] = 1;
    m_vData[2][0] = -sin(angle);
    m_vData[0][2] = sin(angle);
    m_vData[2][2] = cos(angle);
    m_vData[3][3] = 1;
}

RotateOzMatrix::RotateOzMatrix(double angle) {
    m_vData[0][0] = cos(angle);
    m_vData[0][1] = -sin(angle);
    m_vData[1][0] = sin(angle);
    m_vData[1][1] = cos(angle);
    m_vData[2][2] = 1;
    m_vData[3][3] = 1;
}

} // namespace math
