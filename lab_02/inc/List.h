//
// Created by denis on 20.04.2021.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include <initializer_list>
#include <memory>

namespace denis
{
template <typename  T>
class list {
public:

    list();
    list(list<T> &&inList); // конструктор перемещения
    list(list<T> &inList); // конструктор копирования
    list(T *const inArray, const int& size);
    list(std::initializer_list<T> nodes);

    ~list() = default;

    list<T> &operator = (const list<T> &inList); // = копирования
    list<T> &operator = (const list<T> &&inList); // = перемещения

private:

    size_t m_size;
    std::shared_ptr<int> m_pHead;
    std::shared_ptr<int> m_pTail;
};
}

#endif //LAB_02_LIST_H
