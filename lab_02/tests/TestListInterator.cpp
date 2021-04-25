//
// Created by denis on 23.04.2021.
//

#include "gtest/gtest.h"
#include "ListIterator.hpp"

TEST(ListIterator, emptyConstructor)
{
    auto iterator = denis::listIterator<int>();
    ASSERT_EQ(iterator.isInvalid(), true);
}

TEST(ListIterator, sharedConstructor)
{
    auto sharedNode = std::make_shared<denis::listNode<int>>(10);
    auto iterator = denis::listIterator<int>(sharedNode);

    ASSERT_EQ(iterator.isInvalid(), false);
}

TEST(ListIterator, iteratorConstructor)
{
    auto sharedNode = std::make_shared<denis::listNode<int>>(10);
    auto iter1 = denis::listIterator<int>(sharedNode);
    auto iter2 = denis::listIterator<int>(iter1);

    ASSERT_EQ(iter1->getData(), iter2->getData());
}

TEST(ListIterator, nextFunc)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    node1->setNextNode(node2);
    auto iter = denis::listIterator<int>(node1);
    ASSERT_EQ(iter->getData(), 10);
    iter.next();
    ASSERT_EQ(iter->getData(), 15);
    ASSERT_EQ((*iter).getData(), 15);
}

TEST(ListIterator, operatorPlusEqual)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::listIterator<int>(node1);
    ASSERT_EQ(iter->getData(), 10);
    iter += 2;
    ASSERT_EQ(iter->getData(), 20);
    ASSERT_EQ((*iter).getData(), 20);
}

TEST(ListIterator, operatorPlus)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::listIterator<int>(node1);
    ASSERT_EQ(iter->getData(), 10);
    auto newIter = iter + 2;
    ASSERT_EQ(newIter->getData(), 20);
    ASSERT_EQ((*newIter).getData(), 20);
}

TEST(ListIterator, operatorIncrement)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::listIterator<int>(node1);
    ASSERT_EQ(iter->getData(), 10);
    iter++;
    ASSERT_EQ(iter->getData(), 15);
    iter++;
    ASSERT_EQ(iter->getData(), 20);
}


TEST(ListIterator, operatorIsEqual)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::listIterator<int>(node1);
    auto iter2 = denis::listIterator<int>(iter);
    ASSERT_EQ(iter == iter2, true);
    iter2++;
    ASSERT_EQ(iter == iter2, false);
}

TEST(ListIterator, operatorIsNotEqual)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::listIterator<int>(node1);
    auto iter2 = denis::listIterator<int>(iter);
    ASSERT_EQ(iter != iter2, false);
    iter2++;
    ASSERT_EQ(iter != iter2, true);
}