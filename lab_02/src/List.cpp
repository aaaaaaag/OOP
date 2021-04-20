//
// Created by denis on 20.04.2021.
//

#include <chrono>
#include "List.h"

using namespace denis;

template <typename T>
list<T>::list():
        m_size(0),
        m_pHead(nullptr),
        m_pTail(nullptr)
{
}

template <typename T>
list<T>::list(list<T> &&inList):
        m_size(inList.m_size),
        m_pHead(inList.m_pHead),
        m_pTail(inList.m_pTail)
{
}

template<typename T>
list<T>::list(list<T> &inList):
        m_size(inList.m_size),
        m_pHead(inList.m_pHead),
        m_pTail(inList.m_pTail)
{
    for (auto node: inList)
    {
        std::shared_ptr<listNode<T>> tmpNode = nullptr;
        try {
            tmpNode = std::make_shared<listNode<T>>(listNode<T>());
        }
        catch (std::bad_alloc& err) {
            auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
        }
        tmpNode->set(node.get());
        //this->
    }
}

template<typename T>
list<T>::list(T *inArray, const int &size) {
    //TODO realise
}

template<typename T>
list<T>::list(std::initializer_list<T> inNodes):
m_size(0),
m_pHead(nullptr),
m_pTail(nullptr)
{
    for (auto node: inNodes)
    {

    }
}

template<typename T>
void list<T>::clear() {
    while (this->m_size)
    {
        this->popFront();
    }
}

template<typename T>
bool list<T>::isEmpty() {
    return this->m_size == 0;
}

template<typename T>
listIterator<T> list<T>::pushFront(const list<T> &list) {
    listIterator<T> iterator;

    for (int i = 0; i < list.size; i++)
        iterator = this->insert(this->begin() + i, (*(list.cbegin() + i)).get());

    return iterator;
}

template<typename T>
listIterator<T> list<T>::pushFront(const T &data) {
    std::shared_ptr<listNode<T>> temp_node = nullptr;

    //TODO add try catch block

    temp_node->set(data);
    return this->push_front(temp_node);
}

template<typename T>
listIterator<T> list<T>::pushBack(const T &data) {
    std::shared_ptr<listNode<T>> node = nullptr;

    //TODO add try catch block

    node->set(data);
    return this->push_back(node);
}

template<typename T>
listIterator<T> list<T>::pushBack(const list<T> &list) {
    for (auto current = list.cbegin(); current != list.cend(); current++)
        this->push_back((*current).get());

    listIterator<T> iterator(this->tail);
    return iterator;
}

template<typename T>
listIterator<T> list<T>::insert(const listIterator<T> &iterator, const T &data) {
    if (iterator.isInvalid())
    {
        //TODO error process
    }

    std::shared_ptr<listNode<T>> tmpNode = nullptr;

    try
    {
        tmpNode = std::shared_ptr<listNode<T>>(new listNode<T>); // maybe std make_shared
    } catch (std::bad_alloc &error) {
        //TODO error process
    }

    tmpNode->set(data);

    if (iterator == this->begin())
        return pushFront(tmpNode);
    else if (iterator == this->end())
        return this->pushBack(tmpNode);

    listIterator<T> temp_iterator = this->begin();
    for (; temp_iterator + 1 != iterator; temp_iterator++);

    tmpNode->set_next(temp_iterator->get_next());
    temp_iterator->set_next(tmpNode);
    this->size++;

    listIterator<T> insertIterator(tmpNode);
    return insertIterator;
}

template<typename T>
listIterator<T> list<T>::insert(const listIterator<T> &iterator, const list<T> &list) {
    if (iterator.isInvalid())
    {
        //TODO error process
    }

    listIterator<T> insertIterator;
    for (int i = 0; i < list.size; i++)
        insertIterator = insert(iterator, (*(list.cbegin() + i)).get());

    return insertIterator;
}

template<typename T>
listIterator<T> list<T>::insert(const constListIterator<T> &iterator, const T &data) {
    if (iterator.isInvalid())
    {
        //TODO error process
    }

    std::shared_ptr<listNode<T>> tmpNode = nullptr;

    try
    {
        tmpNode = std::shared_ptr<listNode<T>>(new listNode<T>);
    } catch (std::bad_alloc &err) {
        //TODO error process
    }

    tmpNode->set(data);

    if (iterator == this->cbegin())
        return push_front(tmpNode);
    else if (iterator == this->cend())
        return this->push_back(tmpNode);

    listIterator<T> tmpIterator = this->begin();
    for (; tmpIterator + 1 != iterator; tmpIterator++);

    tmpNode->set_next(tmpIterator->get_next());
    tmpIterator->set_next(tmpNode);
    this->size++;

    listIterator<T> insertIterator(tmpNode);
    return insertIterator;
}

template<typename T>
listIterator<T> list<T>::insert(const constListIterator<T> &iterator, const list <T> &list) {
    if (iterator.isInvalid())
    {
        //TODO error process
    }

    listIterator<T> insertIterator;
    for (int i = 0; i < list.size; i++)
        insertIterator = insert(iterator, (*(list.cbegin() + i)).get());

    return insertIterator;
}




