#ifndef MESH_H
#define MESH_H

#include <memory>
#include "../exceptions/ModelBuildException.h"
#include "../math/Matrix.h"
#include "../math/Point.h"

namespace objects {

using math::Point;

class Mesh {
public:
    void addPoint(Point &p);
    void addEdge(size_t first, size_t second);
    void transform(std::shared_ptr<math::Matrix> matrix);
    std::vector<std::pair<Point, Point>> getLines();
private:
    std::vector<Point> m_vPoints;
    std::vector<std::pair<size_t, size_t>> m_vEdges;
};

} // namespace objects

#endif // MESH_H
