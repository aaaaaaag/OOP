//
// Created by denis on 20.04.2021.
//

#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include "ListNode.h"

//using namespace denis;

template <typename T>
denis::listNode<T>::listNode():
m_pNextNode(nullptr)
{
}

template<typename T>
denis::listNode<T>::listNode(const T &inData):
m_pNextNode(nullptr),
m_data(inData)
{
}

template<typename T>
denis::listNode<T>::listNode(std::shared_ptr<listNode<T>>& inNode):
m_pNextNode(inNode->m_pNextNode),
m_data(inNode->m_data)
{
}

template<typename T>
void denis::listNode<T>::setData(const T &inData) {
    this->m_data = inData;
}

template<typename T>
void denis::listNode<T>::setNextNode(const std::shared_ptr<listNode<T>> &inNextNode) {
    this->m_pNextNode = inNextNode;
}

template<typename T>
void denis::listNode<T>::setNextNode(const listNode<T> &inNode) {
    auto pNode = std::make_shared<listNode<T>>(inNode);
    this->m_pNextNode = pNode;
}

template<typename T>
const T &denis::listNode<T>::get() const {
    return this->m_data;
}

template<typename T>
T &denis::listNode<T>::getData() {
    return this->m_data;
}

template<typename T>
std::shared_ptr<denis::listNode<T>> denis::listNode<T>::getNextNode() const {
    return this->m_pNextNode;
}

template<typename T>
void denis::listNode<T>::setNull() {
    this->m_pNextNode = nullptr;
}

template<typename T>
bool denis::listNode<T>::operator==(const std::shared_ptr<listNode<T>> &cmpNode) const {
    return this == cmpNode;
}

template<typename T>
bool denis::listNode<T>::operator!=(const std::shared_ptr<listNode<T>> &cmpNode) const {
    return this != cmpNode;
}

#endif



