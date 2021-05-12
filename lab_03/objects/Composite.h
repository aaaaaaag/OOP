#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>
#include "Object.h"

namespace objects {

class Composite: public Object {
public:
    Composite() = default;

    void add(const std::shared_ptr<Object>& obj);
    void remove(size_t ind);
    ssize_t getIndex(const std::shared_ptr<Object>& obj); // TODO why ssize_t

    std::vector<std::shared_ptr<Object>> getObjects();

    void transform(const std::shared_ptr<Matrix> matrix) override;
    void accept(std::shared_ptr<Visitor> visitor) override;
private:
    std::vector<std::shared_ptr<Object>> m_vObjects;
};

} // namespace objects
#endif // COMPOSITE_H
