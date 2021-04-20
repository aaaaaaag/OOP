//
// Created by denis on 20.04.2021.
//

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
    /*
     * code with nodes
     */
}
