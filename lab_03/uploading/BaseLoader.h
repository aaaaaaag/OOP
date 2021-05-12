#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include <string>
#include "../objects/Model.h"

namespace uploading {

using objects::Model;

class BaseLoader
{
public:
    virtual ~BaseLoader() = default;

    virtual void open(std::string sourceName) = 0;
    virtual void close() = 0;
    virtual void readModelInfo(Model &model) = 0;
    virtual void readModel(Model &model) = 0;
};

} // namespace uploading

#endif // BASE_LOADER_H
