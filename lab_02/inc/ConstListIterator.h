//
// Created by denis on 20.04.2021.
//

#ifndef LAB_02_OOP_CONSTLISTITERATOR_H
#define LAB_02_OOP_CONSTLISTITERATOR_H

#include "ListNode.h"
#include "ListIterator.h"

namespace denis {
    template <typename T>
    class constListIterator {
    public:
        constListIterator();
        explicit constListIterator(const std::shared_ptr<listNode<T>> &node);
        constListIterator(const constListIterator<T> &iterator);

        ~constListIterator() = default;

        virtual void next();
        virtual bool isInvalid() const;

        const listNode<T> *operator ->() const;
        const listNode<T> &operator *() const;
        operator bool() const;

        constListIterator<T> &operator += (const int &size);
        constListIterator<T> operator + (const int &size) const;
        constListIterator<T>& operator = (const listIterator<T> &iterator);
        constListIterator<T> &operator ++ ();

        bool operator != (const constListIterator<T> &iterator) const;
        bool operator == (const constListIterator<T> &iterator) const;

    protected:
        std::weak_ptr<listNode<T>> m_pNode;

    };
}
#endif //LAB_02_OOP_CONSTLISTITERATOR_H
