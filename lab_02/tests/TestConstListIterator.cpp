//
// Created by denis on 24.04.2021.
//

#include "gtest/gtest.h"
#include "ConstListIterator.hpp"

TEST(ConstListIterator, emptyConstructor)
{
    auto iterator = denis::constListIterator<int>();
    ASSERT_EQ(iterator.isInvalid(), true);
}

TEST(ConstListIterator, sharedConstructor)
{
    auto sharedNode = std::make_shared<denis::listNode<int>>(10);
    auto iterator = denis::constListIterator<int>(sharedNode);

    ASSERT_EQ(iterator.isInvalid(), false);
}

TEST(ConstListIterator, iteratorConstructor)
{
    auto sharedNode = std::make_shared<denis::listNode<int>>(10);
    auto iter1 = denis::constListIterator<int>(sharedNode);
    auto iter2 = denis::constListIterator<int>(iter1);

    ASSERT_EQ(iter1->get(), iter2->get());
}

TEST(ConstListIterator, nextFunc)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    node1->setNextNode(node2);
    auto iter = denis::constListIterator<int>(node1);
    ASSERT_EQ(iter->get(), 10);
    iter.next();
    ASSERT_EQ(iter->get(), 15);
    ASSERT_EQ((*iter).get(), 15);
}

TEST(ConstListIterator, operatorPlusEqual)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::constListIterator<int>(node1);
    ASSERT_EQ(iter->get(), 10);
    iter += 2;
    ASSERT_EQ(iter->get(), 20);
    ASSERT_EQ((*iter).get(), 20);
}

TEST(ConstListIterator, operatorPlus)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::constListIterator<int>(node1);
    ASSERT_EQ(iter->get(), 10);
    auto newIter = iter + 2;
    ASSERT_EQ(newIter->get(), 20);
    ASSERT_EQ((*newIter).get(), 20);
}

TEST(ConstListIterator, operatorIncrement)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::constListIterator<int>(node1);
    ASSERT_EQ(iter->get(), 10);
    iter++;
    ASSERT_EQ(iter->get(), 15);
    iter++;
    ASSERT_EQ(iter->get(), 20);
}


TEST(ConstListIterator, operatorIsEqual)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::constListIterator<int>(node1);
    auto iter2 = denis::constListIterator<int>(iter);
    ASSERT_EQ(iter == iter2, true);
    iter2++;
    ASSERT_EQ(iter == iter2, false);
}

TEST(ConstListIterator, operatorIsNotEqual)
{
    auto node1 = std::make_shared<denis::listNode<int>>(10);
    auto node2 = std::make_shared<denis::listNode<int>>(15);
    auto node3 = std::make_shared<denis::listNode<int>>(20);
    node2->setNextNode(node3);
    node1->setNextNode(node2);
    auto iter = denis::constListIterator<int>(node1);
    auto iter2 = denis::constListIterator<int>(iter);
    ASSERT_EQ(iter != iter2, false);
    iter2++;
    ASSERT_EQ(iter != iter2, true);
}