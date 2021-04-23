//
// Created by denis on 20.04.2021.
//

#ifndef LAB_02_OOP_LISTITERATOR_H
#define LAB_02_OOP_LISTITERATOR_H


#include <memory>
#include "ListNode.hpp"
namespace denis {
    template<typename T>
class listIterator: public std::iterator<std::input_iterator_tag, T> {
public:
    listIterator();
    explicit listIterator(const std::shared_ptr<listNode<T>> &node);
    listIterator(const listIterator<T> &iterator);

    ~listIterator() = default;

    virtual void next();
    [[nodiscard]] virtual bool isInvalid() const;

    listNode<T> *operator ->();
    const listNode<T> *operator ->() const;

    const listNode<T> &operator *() const;
    listNode<T> &operator *();

    explicit operator bool() const;

    listIterator<T> &operator += (const int &size);
    listIterator<T> operator + (const int &size) const;
    listIterator<T>& operator = (const listIterator<T> &iterator);
    listIterator<T> &operator ++ ();
    listIterator<T> operator ++ (int);

    bool operator != (const listIterator<T> &iterator) const;
    bool operator == (const listIterator<T> &iterator) const;

private:
    std::weak_ptr<listNode<T>> m_pNode;
    };
}

#endif //LAB_02_OOP_LISTITERATOR_H
