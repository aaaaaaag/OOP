#ifndef ABS_MODEL_LOADER_H
#define ABS_MODEL_LOADER_H

#include "memory"
#include "BaseLoaderImp.h"
#include "../objects/Model.h"

namespace uploading {

using objects::Model;

class AbsModelLoader {
public:
    AbsModelLoader() = default;
    virtual ~AbsModelLoader() = default;
    virtual std::shared_ptr<Model> loadModel(std::string sourceName, std::string modelName) = 0;
};

} // namespace uploading

#endif // ABS_MODEL_LOADER_H
