//
// Created by denis on 20.04.2021.
//

#ifndef LIST_HPP
#define LIST_HPP

#include <chrono>
#include "List.h"
#include "ErrorExceptions.hpp"

template <typename T>
denis::list<T>::list():
        m_size(0),
        m_pHead(nullptr),
        m_pTail(nullptr)
{
}

template <typename T>
denis::list<T>::list(denis::list<T> &&inList) noexcept :
        m_size(inList.m_size),
        m_pHead(inList.m_pHead),
        m_pTail(inList.m_pTail)
{
}

template<typename T>
denis::list<T>::list(denis::list<T> &inList):
        m_size(inList.m_size),
        m_pHead(inList.m_pHead),
        m_pTail(inList.m_pTail)
{

    if (!inList.begin())
        return;
    for (auto node: inList)
    {
        std::shared_ptr<denis::listNode<T>> tmpNode;
        try
        {
            tmpNode = std::make_shared<denis::listNode<T>>();
        } catch (std::bad_alloc &error) {
            time_t curTime = time(nullptr);
            auto curLocalTime = localtime(&curTime);
            throw MemoryError(asctime(curLocalTime), __FILE__, __LINE__, "Shared_ptr allocate error");
        }
        tmpNode->setNextNode(node.getNextNode());
    }
}

template<typename T>
denis::list<T>::list(const T *inArray, const int &size) {
    if (!inArray)
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "Empty array");
    }

    if (size <= 0)
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "Incorrect size arg( <= 0)");
    }

    this->m_size = 0;
    this->m_pHead = nullptr;
    this->m_pTail = nullptr;

    for (int i = 0; i < size; i++)
        this->pushBack(*(inArray + i));
}

template<typename T>
denis::list<T>::list(std::initializer_list<T> inNodes):
m_size(0),
m_pHead(nullptr),
m_pTail(nullptr)
{
    for (auto node: inNodes)
        this->pushBack(node);
}

template<typename T>
void denis::list<T>::clear() {
    while (this->m_size)
        this->popFront();
}

template<typename T>
bool denis::list<T>::isEmpty() {
    return this->m_size == 0;
}

template<typename T>
denis::listIterator<T> denis::list<T>::pushFront(const denis::list<T> &list) {
    denis::listIterator<T> iterator;

    for (int i = 0; i < list.m_size; i++)
        iterator = this->insert(this->begin() + i, (*(list.cbegin() + i)).get());

    return iterator;
}

template<typename T>
denis::listIterator<T> denis::list<T>::pushFront(const T &data) {
    std::shared_ptr<denis::listNode<T>> tmpNode;
    try
    {
        tmpNode = std::make_shared<denis::listNode<T>>();
    } catch (std::bad_alloc &error) {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw MemoryError(asctime(curLocalTime), __FILE__, __LINE__, "Shared_ptr allocate error");
    }

    tmpNode->setData(data);
    return this->pushFront(tmpNode);
}

template<typename T>
denis::listIterator<T> denis::list<T>::pushBack(const T &data) {
    std::shared_ptr<denis::listNode<T>> tmpNode;
    try
    {
        tmpNode = std::make_shared<denis::listNode<T>>();
    } catch (std::bad_alloc &error) {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw MemoryError(asctime(curLocalTime), __FILE__, __LINE__, "Shared_ptr allocate error");
    }

    tmpNode->setData(data);
    return this->pushBack(tmpNode);
}

template<typename T>
denis::listIterator<T> denis::list<T>::pushBack(const denis::list<T> &list) {
    for (auto current = list.cbegin(); current != list.cend(); current++)
        this->pushBack((*current).get());

    denis::listIterator<T> iterator(this->m_pTail);
    return iterator;
}

template<typename T>
denis::listIterator<T> denis::list<T>::insert(const denis::listIterator<T> &iterator, const T &data) {
    if (iterator.isInvalid())
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "Invalid iterator");
    }
    std::shared_ptr<denis::listNode<T>> tmpNode;
    try
    {
        tmpNode = std::make_shared<denis::listNode<T>>();
    } catch (std::bad_alloc &error) {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw MemoryError(asctime(curLocalTime), __FILE__, __LINE__, "Shared_ptr allocate error");
    }

    tmpNode->setData(data);

    if (iterator == this->begin())
        return pushFront(tmpNode);
    else if (iterator == this->end())
        return this->pushBack(tmpNode);

    denis::listIterator<T> temp_iterator = this->begin();
    for (; temp_iterator + 1 != iterator; temp_iterator++);

    tmpNode->setNextNode(temp_iterator->getNextNode());
    temp_iterator->setNextNode(tmpNode);
    this->m_size++;

    denis::listIterator<T> insertIterator(tmpNode);
    return insertIterator;
}

template<typename T>
denis::listIterator<T> denis::list<T>::insert(const denis::listIterator<T> &iterator, const denis::list<T> &list) {
    if (iterator.isInvalid())
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "Invalid iterator");
    }

    denis::listIterator<T> insertIterator;
    for (int i = 0; i < list.m_size; i++)
        insertIterator = insert(iterator, (*(list.cbegin() + i)).get());

    return insertIterator;
}

template<typename T>
denis::listIterator<T> denis::list<T>::insert(const denis::constListIterator<T> &iterator, const T &data) {
    if (iterator.isInvalid())
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "Invalid iterator");
    }

    std::shared_ptr<denis::listNode<T>> tmpNode;
    try
    {
        tmpNode = std::make_shared<denis::listNode<T>>();
    } catch (std::bad_alloc &error) {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw MemoryError(asctime(curLocalTime), __FILE__, __LINE__, "Shared_ptr allocate error");
    }

    tmpNode->setData(data);

    if (iterator == this->cbegin())
        return pushFront(tmpNode);
    else if (iterator == this->cend())
        return this->pushBack(tmpNode);

    denis::listIterator<T> tmpIterator = this->begin();
    for (;  iterator != (tmpIterator + 1); tmpIterator++);

    tmpNode->setNextNode(tmpIterator->getNextNode());
    tmpIterator->setNextNode(tmpNode);
    this->m_size++;

    denis::listIterator<T> insertIterator(tmpNode);
    return insertIterator;
}

template<typename T>
denis::listIterator<T> denis::list<T>::insert(const denis::constListIterator<T> &iterator, const list <T> &list) {
    if (iterator.isInvalid())
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "Invalid iterator");
    }

    denis::listIterator<T> insertIterator;
    for (int i = 0; i < list.m_size; i++)
        insertIterator = insert(iterator, (*(list.cbegin() + i)).get());

    return insertIterator;
}

template<typename T>
T denis::list<T>::popFront() {
    if (!this->m_size)
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidState(asctime(curLocalTime), __FILE__, __LINE__, "try to pop element in empty list");
    }

    T data = this->m_pHead->get();

    if (this->m_size == 1)
    {
        this->m_pHead = nullptr;
        this->m_pHead = nullptr;
    }
    else
    {
        this->m_pHead = this->m_pHead->getNextNode();
    }

    this->m_size--;

    return data;
}

template<typename T>
T denis::list<T>::popBack() {
    if (!this->m_size)
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidState(asctime(curLocalTime), __FILE__, __LINE__, "try to pop element in empty list");
    }

    T data = this->m_pTail->get();

    if (this->m_size == 1)
    {
        this->m_pHead = nullptr;
        this->m_pTail = nullptr;
    }
    else
    {
        std::shared_ptr<listNode<T>> tmpNode = this->m_pHead;
        for (; tmpNode->getNextNode() != this->m_pTail; tmpNode = tmpNode->getNextNode());

        tmpNode->setNull();
        this->m_pTail = tmpNode;
        this->m_pTail->setNull();
    }

    this->m_size--;

    return data;
}

template<typename T>
T denis::list<T>::remove(const denis::listIterator<T> &inIterator) {
    if (inIterator.isInvalid())
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "Invalid iterator");
    }

    if (!this->m_size)
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidState(asctime(curLocalTime), __FILE__, __LINE__, "try to pop element in empty list");
    }

    if (inIterator == this->begin())
    {
        return popFront();
    }

    denis::listIterator<T> tmpIterator = this->begin();
    for (; tmpIterator + 1 != inIterator; tmpIterator++);

    T data = tmpIterator->get();
    tmpIterator->setNextNode(tmpIterator->getNextNode()->getNextNode());
    this->m_size--;

    return data;
}

template<typename T>
void denis::list<T>::reverse() {
    std::shared_ptr<listNode<T>> current(this->m_pHead);
    std::shared_ptr<listNode<T>> next(nullptr);
    std::shared_ptr<listNode<T>> prev(nullptr);

    while (current)
    {
        next = current->getNextNode();
        current->setNextNode(prev);
        prev = current;
        current = next;
    }

    prev = this->m_pHead;
    this->m_pHead = this->m_pTail;
    this->m_pTail = prev;
    this->m_pTail->setNull();
}

template<typename T>
denis::list<T> &denis::list<T>::operator=(const denis::list<T> &inList) {
    clear();

    this->m_size = 0;
    this->m_pHead = nullptr;
    this->m_pTail = nullptr;

    pushBack(inList);
    return *this;
}

template<typename T>
denis::list<T> &denis::list<T>::operator=(denis::list<T> &&inList)  noexcept {
    this->m_size = inList.m_size;
    this->m_pHead = inList.m_pHead;
    this->m_pTail = inList.m_pTail;
}

template<typename T>
denis::list<T> &denis::list<T>::merge(const denis::list<T> &list) {
    this->pushBack(list);
    return *this;
}

template<typename T>
denis::list<T> &denis::list<T>::merge(const T &data) {
    this->pushBack(data);
    return *this;
}

template<typename T>
denis::list<T> &denis::list<T>::operator + (const denis::list<T> &list) {
    this->pushBack(list);
    return *this;
}

template<typename T>
denis::list<T> &denis::list<T>::operator + (const T &data) {
    this->pushBack(data);
    return *this;
}

template<typename T>
denis::list<T> &denis::list<T>::operator+=(const list <T> &list) {
    this->pushBack(list);
    return *this;
}

template<typename T>
denis::list<T> &denis::list<T>::operator+=(const T &data) {
    this->pushBack(data);
    return *this;
}

template<typename T>
bool denis::list<T>::operator==(const list <T> &list) const {
    auto fst = this->cbegin();
    auto snd = list.cbegin();

    for (; fst != this->cend() && snd != list.cend(); ++fst, ++snd)
    {
        if (fst->get() != snd->get())
            return false;
    }

    return this->m_size == list.m_size;
}

template<typename T>
bool denis::list<T>::operator!=(const list <T> &list) const {
    return !(*this == list);
}

template<typename T>
denis::listIterator<T> denis::list<T>::begin() {
    denis::listIterator<T> iterator(this->m_pHead);
    return iterator;
}

template<typename T>
denis::constListIterator<T> denis::list<T>::cbegin() const {
    denis::constListIterator<T> iterator(this->m_pHead);
    return iterator;
}

template<typename T>
denis::listIterator<T> denis::list<T>::end() {
    denis::listIterator<T> iterator(this->m_pTail);
    return ++iterator;
}

template<typename T>
denis::constListIterator<T> denis::list<T>::cend() const {
    denis::constListIterator<T> iterator(this->m_pTail);
    return ++iterator;
}

template<typename T>
std::shared_ptr<denis::listNode<T>> denis::list<T>::getHeadNode() {
    return this->m_pHead;
}

template<typename T>
std::shared_ptr<denis::listNode<T>> denis::list<T>::getTailNode() {
    return this->m_pTail;
}

template<typename T>
denis::listIterator<T> denis::list<T>::pushBack(const std::shared_ptr<listNode<T>> &node) {
    if (!node)
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "empty in node");
    }

    std::shared_ptr<denis::listNode<T>> tmpNode;
    try
    {
        tmpNode = std::make_shared<denis::listNode<T>>();
    } catch (std::bad_alloc &error) {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw MemoryError(asctime(curLocalTime), __FILE__, __LINE__, "Shared_ptr allocate error");
    }

    tmpNode->setData(node->get());

    if (!this->m_size)
    {
        this->m_pHead = tmpNode;
        this->m_pTail = tmpNode;
    }
    else
    {
        this->m_pTail->setNextNode(tmpNode);
        this->m_pTail = tmpNode;
    }

    this->m_size++;

    denis::listIterator<T> iterator(this->m_pTail);
    return iterator;
}

template<typename T>
denis::listIterator<T> denis::list<T>::pushFront(const std::shared_ptr<listNode<T>> &node) {
    if (!node)
    {
        time_t curTime = time(nullptr);
        auto curLocalTime = localtime(&curTime);
        throw InvalidArgument(asctime(curLocalTime), __FILE__, __LINE__, "empty in node");
    }

    node->setNextNode(this->m_pHead);
    this->m_pHead = node;

    if (!this->m_size)
    {
        this->m_pTail = this->m_pHead;
    }

    this->m_size++;

    denis::listIterator<T> iterator(node);
    return iterator;
}

template<typename T>
size_t denis::list<T>::size() {
    return m_size;
}

template<typename T>
template<typename iter>
denis::list<T>::list(const iter& begin, const iter& end)
{
    m_size = 0;
    m_pHead = nullptr;
    m_pTail = nullptr;
    for (auto iter = begin; iter != end; iter++)
        pushBack(iter);
}

template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::pushFront(const iter& begin, const iter& end)
{
    denis::list<T> listNew(begin, end);
    pushFront(listNew);
}

template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::pushFront(const iter& begin, size_t count)
{
    iter end = begin;
    for (int i = 0; i < count; i++, end++);
    denis::list<T> listNew(begin, end);
    pushFront(listNew);
}

template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::pushBack(const iter& begin, const iter& end)
{
    denis::list<T> listNew(begin, end);
    pushBack(listNew);
}

template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::pushBack(const iter& begin, size_t count)
{
    iter end = begin;
    for (int i = 0; i < count; i++, end++);
    denis::list<T> listNew(begin, end);
    pushBack(listNew);
}

template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::insert(const listIterator<T> &iterator, const iter& begin, const iter& end)
{
    denis::list<T> listNew(begin, end);
    insert(iterator, listNew);
}

template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::insert(const listIterator<T> &iterator, const iter& begin, size_t count)
{
    iter end = begin;
    for (int i = 0; i < count; i++, end++);
    denis::list<T> listNew(begin, end);
    insert(iterator, listNew);
}


template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::insert(const constListIterator<T> &iterator, const iter& begin, const iter& end)
{
    denis::list<T> listNew(begin, end);
    insert(iterator, listNew);
}

template<typename T>
template<typename iter>
denis::listIterator<T> denis::list<T>::insert(const constListIterator<T> &iterator, const iter& begin, size_t count)
{
    iter end = begin;
    for (int i = 0; i < count; i++, end++);
    denis::list<T> listNew(begin, end);
    insert(iterator, listNew);
}

template<typename T>
denis::list<T> denis::list<T>::remove(const listIterator<T> &inIterator, size_t count)
{
    denis::list<T> resList();
    auto iter = inIterator;
    for (int i = 0; i < count; i++, iter++)
        resList.pushBack(remove(iter));

    return resList;
}

template<typename T>
template<typename iter>
denis::list<T>& denis::list<T>::merge(const iter& begin, const iter& end)
{
    denis::list<T> listNew(begin, end);
    return merge(listNew);
}

template<typename T>
template<typename iter>
denis::list<T>& denis::list<T>::merge(const iter& begin, size_t count)
{
    iter end = begin;
    for (int i = 0; i < count; i++, end++);
    denis::list<T> listNew(begin, end);
    return merge(listNew);
}

#endif


