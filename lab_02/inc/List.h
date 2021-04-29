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
        explicit list(list<T> &inList); // конструктор копирования
        list(const T *inArray, const int& size);
        list(std::initializer_list<T> inNodes);
        template <typename iter>
        list(const iter& begin, const iter& end);
        bool isEmpty() override;
        void clear() override;

        listIterator<T> pushFront(const T &data);
        listIterator<T> pushFront(const list<T> &list);
        template <typename iter>
        listIterator<T> pushFront(const iter& begin, const iter& end);
        template <typename iter>
        listIterator<T> pushFront(const iter& begin, size_t count);


        listIterator<T> pushBack(const T &data);
        listIterator<T> pushBack(const list<T> &list);
        template <typename iter>
        listIterator<T> pushBack(const iter& begin, const iter& end);
        template <typename iter>
        listIterator<T> pushBack(const iter& begin, size_t count);


        listIterator<T> insert(const listIterator<T> &iterator, const T &data);
        listIterator<T> insert(const listIterator<T> &iterator, const list<T> &list);
        listIterator<T> insert(const constListIterator<T> &iterator, const T &data);
        listIterator<T> insert(const constListIterator<T> &iterator, const list<T> &list);
        template <typename iter>
        listIterator<T> insert(const listIterator<T> &iterator, const iter& begin, const iter& end);
        template <typename iter>
        listIterator<T> insert(const listIterator<T> &iterator, const iter& begin, size_t count);
        template <typename iter>
        listIterator<T> insert(const constListIterator<T> &iterator, const iter& begin, const iter& end);
        template <typename iter>
        listIterator<T> insert(const constListIterator<T> &iterator, const iter& begin, size_t count);


        T popFront();
        T popBack();

        T remove(const listIterator<T> &inIterator);
        list<T> remove(const listIterator<T> &inIterator, size_t count);
        void reverse();
        size_t size();

        template <typename iter>
        list<T> sublist(const iter& begin, const iter& end);
        template <typename iter>
        list<T> sublist(const iter& begin, size_t count);


        list<T> &merge(const list<T> &list);
        list<T> &merge(const T &data);
        template <typename iter>
        list<T> &merge(const iter& begin, const iter& end);
        template <typename iter>
        list<T> &merge(const iter& begin, size_t count);


        listIterator<T> begin();
        constListIterator<T> begin() const;
        constListIterator<T> cbegin() const;

        listIterator<T> end();
        constListIterator<T> end() const;
        constListIterator<T> cend() const;

        bool isEqual(const list<T>& inList);

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
