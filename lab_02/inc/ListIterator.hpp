//
// Created by denis on 20.04.2021.
//

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "ListIterator.h"

using namespace denis;

template <typename T>
listIterator<T>::listIterator()
{
    this->m_pNode.lock() = nullptr;
}

template<typename T>
listIterator<T>::listIterator(const std::shared_ptr<listNode<T>> &node) {
    this->m_pNode = node;
}

template<typename T>
listIterator<T>::listIterator(const listIterator<T> &iterator) {
    this->m_pNode = iterator.m_pNode.lock();
}

template<typename T>
void listIterator<T>::next() {
    this->m_pNode = this->m_pNode.lock()->getNextNode();
}

template<typename T>
bool listIterator<T>::isInvalid() const {
    return this->m_pNode.lock() == nullptr;
}

template<typename T>
listNode<T> *listIterator<T>::operator->() {
    return this->m_pNode.lock().get();
}

template<typename T>
const listNode<T> *listIterator<T>::operator->() const {
    return this->m_pNode.lock().get();
}

template<typename T>
const listNode<T> &listIterator<T>::operator*() const {
    return *this->m_pNode.lock();
}

template<typename T>
listNode<T> &listIterator<T>::operator*() {
    return *this->m_pNode.lock();
}

template<typename T>
listIterator<T>::operator bool() const {
    return this->m_pNode.lock() != nullptr;
}

template<typename T>
listIterator<T> &listIterator<T>::operator+=(const int &size) {
    for (int i = 0; i < size; i++)
        this->next();

    return *this;
}

template<typename T>
listIterator<T> listIterator<T>::operator+(const int &size) const {
    listIterator<T> new_iterator(*this);
    new_iterator += size;
    return new_iterator;
}

template<typename T>
listIterator<T>& listIterator<T>::operator=(const listIterator<T> &iterator) {
    this->m_pNode = iterator.m_pNode.lock();
    return *this;
}

template<typename T>
listIterator<T> &listIterator<T>::operator++() {
    this->next();
    return *this;
}

template<typename T>
const listIterator<T> listIterator<T>::operator++(int) {
    listIterator<T> new_iterator(*this);
    this->next();
    return new_iterator;
}

template<typename T>
bool listIterator<T>::operator!=(const listIterator<T> &iterator) const {
    return this->m_pNode.lock() != iterator.m_pNode.lock();
}

template<typename T>
bool listIterator<T>::operator==(const listIterator<T> &iterator) const {
    return this->m_pNode.lock() == iterator.m_pNode.lock();
}



#endif