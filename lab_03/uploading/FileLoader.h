#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <fstream>
#include <iostream>
#include "BaseLoaderImp.h"
#include "../math/Point.h"
#include "../objects/Model.h"
#include "../exceptions/FileOpenException.h"

namespace uploading {

using math::Point;
using objects::Model;

class FileLoader: public BaseLoader {
public:
    FileLoader() = default;
    ~FileLoader() override;

    void open(std::string sourceName) override;
    void close() override;
    std::pair<size_t, size_t> readModelInfo() override;
    std::pair<size_t, size_t> readEdgeInfo() override;
    math::Point readPoint() override;
private:
    std::ifstream m_file;
};

} // namespace uploading

#endif // FILE_LOADER_H
