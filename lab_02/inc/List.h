//
// Created by denis on 20.04.2021.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include <initializer_list>


#include "ListNode.hpp"
#include "ListIterator.hpp"
#include "SkeletonContainer.h"
#include "ConstListIterator.hpp"

namespace denis
{
    template <typename  T>
    class list: public ISkeletonContainer {
    public:

        list();
        list(list<T> &&inList) noexcept; // конструктор перемещения
        list(list<T> &inList); // конструктор копирования
        list(T *inArray, const int& size);
        list(const std::initializer_list<T>& inNodes);

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

        T popFront();
        T popBack();

        T remove(const listIterator<T> &inIterator);

        void reverse();
        size_t size();


        list<T> &merge(const list<T> &list);
        list<T> &merge(const T &data);

        listIterator<T> begin();
        constListIterator<T> cbegin() const;

        listIterator<T> end();
        constListIterator<T> cend() const;

        list<T> &operator = (const list<T> &inList); // = копирования
        list<T> &operator = (list<T> &&inList) noexcept; // = перемещения

        list<T> &operator + (const list<T> &list);
        list<T> &operator + (const T &data);

        list<T> &operator += (const list<T> &list);
        list<T> &operator += (const T &data);

        bool operator == (const list<T> &list) const;
        bool operator != (const list<T> &list) const;


    protected:

        std::shared_ptr<listNode<T>> getHeadNode();
        std::shared_ptr<listNode<T>> getTailNode();
        listIterator<T> pushBack(const std::shared_ptr<listNode<T>> &node);
        listIterator<T> pushFront(const std::shared_ptr<listNode<T>> &node);


    private:
        size_t m_size;
        std::shared_ptr<listNode<T>> m_pHead;
        std::shared_ptr<listNode<T>> m_pTail;
    };
}

#endif //LAB_02_LIST_H
