//
// Created by denis on 20.04.2021.
//

#include "ConstListIterator.h"

using namespace denis;

template <typename T>
constListIterator<T>::constListIterator():
m_pNode(nullptr)
{
}

template<typename T>
constListIterator<T>::constListIterator(const std::shared_ptr<listNode<T>> &node):
m_pNode(node)
{
}

template<typename T>
constListIterator<T>::constListIterator(const constListIterator<T> &iterator)
{
    this->m_pNode = iterator.m_pNode.lock();
}

template<typename T>
void constListIterator<T>::next() {
    this->m_pNode = this->m_pNode.lock()->getNext();
}

template<typename T>
bool constListIterator<T>::isInvalid() const {
    return this->m_pNode.lock() == nullptr;
}

template<typename T>
const listNode<T> *constListIterator<T>::operator->() const {
    return this->m_pNode.lock().get();
}

template<typename T>
const listNode<T> &constListIterator<T>::operator*() const {
    return *this->m_pNode.lock().get();
}

template<typename T>
constListIterator<T>::operator bool() const {
    return this->m_pNode.lock() != nullptr;
}

template<typename T>
constListIterator<T> &constListIterator<T>::operator+=(const int &size) {
    for (int i = 0; i < size; i++)
        this->next();

    return *this;
}

template<typename T>
constListIterator<T> constListIterator<T>::operator+(const int &size) const {
    constListIterator<T> new_iterator(*this);
    new_iterator += size;
    return new_iterator;
}

template<typename T>
constListIterator<T> constListIterator<T>::operator=(const listIterator<T> &iterator) {
    this->m_pNode = iterator.m_pNode.lock();
    return *this;
}

template<typename T>
constListIterator<T> &constListIterator<T>::operator++() {
    this->next();
    return *this;
}

template<typename T>
bool constListIterator<T>::operator!=(const constListIterator<T> &iterator) const {
    return this->m_pNode.lock() != iterator.m_pNode.lock();
}

template<typename T>
bool constListIterator<T>::operator==(const constListIterator<T> &iterator) const {
    return this->m_pNode.lock() == iterator.m_pNode.lock();
}
