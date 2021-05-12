#include "Matrix.h"

namespace math {

Matrix::Matrix() {
    m_vData.resize(4);
    for (auto &row: m_vData) {
        row.resize(4);
    }
}

double Matrix::get(size_t i, size_t j) const {
    return m_vData[i][j];
}

void Matrix::set(size_t i, size_t j, double value) {
    m_vData[i][j] = value;
}

} // namespace math