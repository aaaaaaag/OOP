#include "Mesh.h"

namespace objects {

void Mesh::addPoint(math::Point &p) {
    m_vPoints.push_back(p);
}

void Mesh::addEdge(size_t first, size_t second) {
    if (first < 0 || second < 0 || first >= m_vPoints.size() || second >= m_vPoints.size()) {
        throw exceptions::ModelBuildException("Wrong point number");
    }
    m_vEdges.emplace_back(first, second);
}

void Mesh::transform(const std::shared_ptr<math::Matrix> matrix) {
    for (auto &point: m_vPoints) {
        point.transform(matrix);
    }
}

std::vector<std::pair<math::Point, math::Point> > Mesh::getLines() {
    std::vector<std::pair<Point, Point>> lines;
    for (auto &edge: m_vEdges) {
        lines.emplace_back(m_vPoints[edge.first], m_vPoints[edge.second]);
    }

    return lines;
}

} // namespace objects
