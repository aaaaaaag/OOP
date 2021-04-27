//
// Created by denis on 20.04.2021.
//

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "ListIterator.h"

template <typename T>
denis::listIterator<T>::listIterator()
{
    this->m_pNode.lock() = nullptr;
}

template<typename T>
denis::listIterator<T>::listIterator(const std::shared_ptr<listNode<T>> &node) {
    this->m_pNode = node;
}

template<typename T>
denis::listIterator<T>::listIterator(const denis::listIterator<T> &iterator) {
    this->m_pNode = iterator.m_pNode.lock();
}

template<typename T>
void denis::listIterator<T>::next() {
    if (this->m_pNode.lock() == nullptr)
        return;
    this->m_pNode = this->m_pNode.lock()->getNextNode();
}

template<typename T>
bool denis::listIterator<T>::isInvalid() const {
    return this->m_pNode.lock() == nullptr;
}

template<typename T>
denis::listNode<T> *denis::listIterator<T>::operator->() {
    return this->m_pNode.lock().get();
}

template<typename T>
const denis::listNode<T> *denis::listIterator<T>::operator->() const {
    return this->m_pNode.lock().get();
}

template<typename T>
const denis::listNode<T> &denis::listIterator<T>::operator*() const {
    return *this->m_pNode.lock();
}

template<typename T>
denis::listNode<T> &denis::listIterator<T>::operator*() {
    return *this->m_pNode.lock();
}

template<typename T>
denis::listIterator<T>::operator bool() const {
    return this->m_pNode.lock() != nullptr;
}

template<typename T>
denis::listIterator<T> &denis::listIterator<T>::operator+=(const int &size) {
    for (int i = 0; i < size; i++)
        this->next();

    return *this;
}

template<typename T>
denis::listIterator<T> denis::listIterator<T>::operator+(const int &size) const {
    denis::listIterator<T> new_iterator(*this);
    new_iterator += size;
    return new_iterator;
}

template<typename T>
denis::listIterator<T>& denis::listIterator<T>::operator=(const denis::listIterator<T> &iterator) {
    this->m_pNode = iterator.m_pNode.lock();
    return *this;
}

template<typename T>
denis::listIterator<T> &denis::listIterator<T>::operator++() {

    this->next();
    return *this;
}

template<typename T>
const denis::listIterator<T> denis::listIterator<T>::operator++(int) {
    denis::listIterator<T> new_iterator(*this);
    this->next();
    return new_iterator;
}

template<typename T>
bool denis::listIterator<T>::operator!=(const denis::listIterator<T> &iterator) const {
    return this->m_pNode.lock() != iterator.m_pNode.lock();
}

template<typename T>
bool denis::listIterator<T>::operator==(const denis::listIterator<T> &iterator) const {
    return this->m_pNode.lock() == iterator.m_pNode.lock();
}

template<typename T>
bool denis::listIterator<T>::operator!=(const denis::constListIterator<T> &iterator) const {
    return this->m_pNode.lock() != iterator.m_pNode.lock();
}

template<typename T>
bool denis::listIterator<T>::operator==(const denis::constListIterator<T> &iterator) const {
    return this->m_pNode.lock() == iterator.m_pNode.lock();
}


#endif