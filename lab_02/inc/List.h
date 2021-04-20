//
// Created by denis on 20.04.2021.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include <initializer_list>


#include "ListNode.h"
#include "ListIterator.h"
#include "SkeletonContainer.h"
#include "ConstListIterator.h"

namespace denis
{
template <typename  T>
class list: public ISkeletonContainer {
public:

    list();
    list(list<T> &&inList); // конструктор перемещения
    list(list<T> &inList); // конструктор копирования
    list(T *inArray, const int& size);
    list(std::initializer_list<T> inNodes);

    ~list() = default;

    bool isEmpty() override;
    void clear() override;

    listIterator<T> pushFront(const T &data);
    listIterator<T> pushFront(const list<T> &list);

    listIterator<T> pushBack(const T &data);
    listIterator<T> pushBack(const list<T> &list);

    listIterator<T> insert(const listIterator<T> &iterator, const T &data);
    listIterator<T> insert(const listIterator<T> &iterator, const list<T> &list);
    listIterator<T> insert(const constListIterator<T> &iterator, const T &data);
    listIterator<T> insert(const constListIterator<T> &iterator, const list<T> &list);

    T pop_front();
    T pop_back();




    list<T> &operator = (const list<T> &inList); // = копирования
    list<T> &operator = (const list<T> &&inList); // = перемещения

protected:

    std::shared_ptr<listNode<T>> getHeadNode();
    std::shared_ptr<listNode<T>> getTailNode();




private:
    size_t m_size;
    std::shared_ptr<listNode<T>> m_pHead;
    std::shared_ptr<listNode<T>> m_pTail;
};
}

#endif //LAB_02_LIST_H
