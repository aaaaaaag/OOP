#include "FileLoader.h"

namespace uploading {

FileLoader::~FileLoader() {
    m_file.close();
}

void FileLoader::open(std::string sourceName) {
    if (m_file.is_open())
        close();

    m_file.open(sourceName);
    if (!m_file)
        throw exceptions::FileOpenException();
}

void FileLoader::close() {
    if (m_file.is_open()) {
        m_file.close();
    }
}

std::pair<size_t, size_t> FileLoader::readModelInfo() {
    if (!m_file.is_open()) {
        throw exceptions::FileOpenException();
    }

    size_t points = 0;
    size_t edges = 0;
    m_file >> points >> edges;

    return std::make_pair(points, edges);
}

Point FileLoader::readPoint() {
    double x = -1, y = -1, z = -1;
    m_file >> x >> y >> z;
    return {x, y, z};
}

std::pair<size_t, size_t> FileLoader::readEdgeInfo() {
    int num1 = -1, num2 = -1;
    m_file >> num1 >> num2;
    return std::make_pair(num1, num2);
}

} // namespace uploading
