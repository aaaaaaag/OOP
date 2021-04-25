//
// Created by denis on 23.04.2021.
//

#include "gtest/gtest.h"
#include "ListNode.hpp"

TEST(ListNode, emptyConstructor)
{
    auto node = denis::listNode<int>();

    ASSERT_EQ(node.getNextNode(), nullptr);
}

TEST(ListNode, dataConstructor)
{
    int testNumb = 10;
    auto node = denis::listNode<int>(testNumb);
    ASSERT_EQ(node.getNextNode(), nullptr);
    ASSERT_EQ(node.getData(), testNumb);
}

TEST(ListNode, anotherNodeConstructor)
{
    int testNumb = 10;
    auto anotherNode = denis::listNode<int>(testNumb);
    auto mainNode = denis::listNode<int>(anotherNode);
    ASSERT_EQ(mainNode.getNextNode(), nullptr);
    ASSERT_EQ(mainNode.getData(), testNumb);
}

TEST(ListNode, setDataFunc)
{
    int data = 10;
    auto node = denis::listNode<int>(data);
    ASSERT_EQ(node.getData(), data);
    int newData = 15;
    node.setData(15);
    ASSERT_EQ(node.getData(), newData);
}

TEST(ListNode, setNextNodeBySharedNode)
{
    auto node = denis::listNode<int>();
    auto newNode = std::make_shared<denis::listNode<int>>();
    node.setNextNode(newNode);
    ASSERT_EQ(node.getNextNode(), newNode);
}

TEST(ListNode, setNextNodeByObjectNode)
{
    auto node = denis::listNode<int>(10);
    auto anotherNode = denis::listNode<int>(10);
    node.setNextNode(anotherNode);
    ASSERT_EQ(node.getNextNode()->getData(), anotherNode.getData());
    ASSERT_EQ(node.getNextNode()->getNextNode(), anotherNode.getNextNode());
}

TEST(ListNode, get)
{
    auto node = denis::listNode<int>(10);
    int num = node.get();
    ASSERT_EQ(num, 10);
}

TEST(ListNode, getData)
{
    auto node = denis::listNode<int>(10);
    int num = node.getData();
    ASSERT_EQ(num, 10);
}

TEST(ListNode, getNextNode)
{
    auto node = denis::listNode<int>();
    ASSERT_EQ(node.getNextNode(), nullptr);
}

TEST(ListNode, setNull)
{
    auto node = denis::listNode<int>();
    node.setNextNode(std::make_shared<denis::listNode<int>>());
    ASSERT_NE(node.getNextNode(), nullptr);
    node.setNull();
    ASSERT_EQ(node.getNextNode(), nullptr);
}

TEST(ListNode, operatorEqual)
{
    auto node = std::make_shared<denis::listNode<int>>();
    auto anotherNode = std::make_shared<denis::listNode<int>>();
    node->setNextNode(anotherNode);

    ASSERT_EQ(node == node, true);
    ASSERT_NE(node == anotherNode, true);
    ASSERT_EQ(node->getNextNode() == anotherNode, true);
}

TEST(ListNode, operatorNotEqual)
{
    auto node = std::make_shared<denis::listNode<int>>();
    auto anotherNode = std::make_shared<denis::listNode<int>>();
    node->setNextNode(anotherNode);

    ASSERT_EQ(node != node, false);
    ASSERT_NE(node != anotherNode, false);
    ASSERT_EQ(node->getNextNode() != anotherNode, false);
}