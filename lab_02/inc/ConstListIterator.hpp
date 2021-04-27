//
// Created by denis on 20.04.2021.
//

#include "ConstListIterator.h"

template <typename T>
denis::constListIterator<T>::constListIterator()
{
    this->m_pNode.lock() = nullptr;
}

template<typename T>
denis::constListIterator<T>::constListIterator(const std::shared_ptr<listNode<T>> &node)
{
    this->m_pNode = node;
}

template<typename T>
denis::constListIterator<T>::constListIterator(const denis::constListIterator<T> &iterator)
{
    this->m_pNode = iterator.m_pNode.lock();
}

template<typename T>
void denis::constListIterator<T>::next() {
    if (this->m_pNode.lock() == nullptr)
        return;
    this->m_pNode = this->m_pNode.lock()->getNextNode();
}

template<typename T>
bool denis::constListIterator<T>::isInvalid() const {
    return this->m_pNode.lock() == nullptr;
}

template<typename T>
const denis::listNode<T> *denis::constListIterator<T>::operator->() const {
    return this->m_pNode.lock().get();
}

template<typename T>
const denis::listNode<T> &denis::constListIterator<T>::operator*() const {
    return *this->m_pNode.lock().get();
}

template<typename T>
denis::constListIterator<T>::operator bool() const {
    return this->m_pNode.lock() != nullptr;
}

template<typename T>
denis::constListIterator<T> &denis::constListIterator<T>::operator+=(const int &size) {
    for (int i = 0; i < size; i++)
        this->next();

    return *this;
}

template<typename T>
denis::constListIterator<T> denis::constListIterator<T>::operator+(const int &size) const {
    denis::constListIterator<T> new_iterator(*this);
    new_iterator += size;
    return new_iterator;
}

template<typename T>
denis::constListIterator<T>& denis::constListIterator<T>::operator=(const listIterator<T> &iterator) {
    this->m_pNode = iterator.m_pNode.lock();
    return *this;
}

template<typename T>
denis::constListIterator<T> &denis::constListIterator<T>::operator++() {
    this->next();
    return *this;
}

template<typename T>
bool denis::constListIterator<T>::operator!=(const denis::constListIterator<T> &iterator) const {
    return this->m_pNode.lock() != iterator.m_pNode.lock();
}

template<typename T>
bool denis::constListIterator<T>::operator==(const denis::constListIterator<T> &iterator) const {
    return this->m_pNode.lock() == iterator.m_pNode.lock();
}

template<typename T>
const denis::constListIterator<T> denis::constListIterator<T>::operator++(int) {
    this->next();
    return *this;
}

template<typename T>
bool denis::constListIterator<T>::operator!=(const denis::listIterator<T> &iterator) const {
    return this->m_pNode.lock() != iterator.m_pNode.lock();
}

template<typename T>
bool denis::constListIterator<T>::operator==(const denis::listIterator<T> &iterator) const {
    return this->m_pNode.lock() == iterator.m_pNode.lock();
}
