#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include "ModelBuilder.h"
#include "AbsModelLoader.h"
#include "memory"
#include "BaseLoaderImp.h"

namespace uploading {

using objects::Model;

class ModelLoader: public AbsModelLoader {
public:
    explicit ModelLoader(BaseLoader *loader);
    std::shared_ptr<Model> loadModel(std::string sourceName, std::string modelName) override;
private:
    std::unique_ptr<BaseLoader> m_pLoader;
    std::unique_ptr<ModelBuilder> m_pBuilder;
};

} // namespace uploading

#endif // MODEL_LOADER_H
