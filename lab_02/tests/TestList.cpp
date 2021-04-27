//
// Created by denis on 24.04.2021.
//

#include "gtest/gtest.h"
#include "List.hpp"

TEST(List, emptyConstructor)
{
    auto list = denis::list<int>();
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(List, moveConstructor)
{
    auto list = denis::list<int>(denis::list<int>());
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(List, copyConstructor)
{
    std::vector<int> vector{0, 1, 2};
    auto copList = denis::list<int>(vector.data(), vector.size());
    auto list = denis::list<int>(copList);
    ASSERT_EQ(list.isEmpty(), false);
}

TEST(List, arrayConstructor)
{
    std::vector<int> vector{0, 1, 2};
    auto list = denis::list<int>(vector.data(), vector.size());
    ASSERT_EQ(list.isEmpty(), false);
    ASSERT_EQ(list.popBack(), 2);
    ASSERT_EQ(list.popBack(), 1);
    ASSERT_EQ(list.popBack(), 0);
}

TEST(List, initializerListConstructor)
{
    denis::list<int> l {0, 1, 2};
    ASSERT_EQ(l.isEmpty(), false);
    ASSERT_EQ(l.popBack(), 2);
    ASSERT_EQ(l.popBack(), 1);
    ASSERT_EQ(l.popBack(), 0);
}

TEST(List, clearFunc)
{
    denis::list<int> l {0, 1, 2};
    ASSERT_EQ(l.isEmpty(), false);
    ASSERT_EQ(l.popBack(), 2);
    ASSERT_EQ(l.popBack(), 1);
    ASSERT_EQ(l.popBack(), 0);
    l.clear();
    ASSERT_EQ(l.isEmpty(), true);
}

TEST(List, pushFrontList)
{
    denis::list<int> l {0, 1, 2};
    denis::list<int> list {0};
    list.pushFront(l);
    ASSERT_EQ(list.isEmpty(), false);
    ASSERT_EQ(list.popBack(), 0);
    ASSERT_EQ(list.popBack(), 2);
    ASSERT_EQ(list.popBack(), 1);
    ASSERT_EQ(list.popBack(), 0);
}

TEST(List, pushFrontData)
{
    auto list = denis::list<int>();
    list.pushFront(10);
    list.pushFront(15);
    ASSERT_EQ(list.popBack(), 10);
    ASSERT_EQ(list.popBack(), 15);
}

TEST(List, pushBackList)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(l);
    ASSERT_EQ(list.isEmpty(), false);
    ASSERT_EQ(list.popBack(), 2);
    ASSERT_EQ(list.popBack(), 1);
    ASSERT_EQ(list.popBack(), 0);
}

TEST(List, pushBackData)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, insertDataByIterator)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.insert(list.begin() + 1, 20);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 20);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, insertDataByIteratorIncorrectIterator)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    try {
        list.insert(list.begin() + 4, 20);
    }
    catch (InvalidArgument& err) {
        ASSERT_EQ(true, true);
        return;
    }
    ASSERT_EQ(false, true);
}

TEST(List, insertListByIterator)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.insert(list.begin() + 1, l);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 2);
    ASSERT_EQ(list.popBack(), 1);
    ASSERT_EQ(list.popBack(), 0);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, insertDataByConstIterator)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.insert(list.cbegin() + 1, 20);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 20);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, insertListByConstIterator)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.insert(list.cbegin() + 1, l);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 2);
    ASSERT_EQ(list.popBack(), 1);
    ASSERT_EQ(list.popBack(), 0);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, popFront)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);;
    ASSERT_EQ(list.popFront(), 10);
    ASSERT_EQ(list.popFront(), 15);
}

TEST(List, remove)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.remove(list.begin());
    ASSERT_EQ(list.popFront(), 15);
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(List, reverse)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.insert(list.cbegin() + 1, l);
    list.reverse();


    ASSERT_EQ(list.popFront(), 15);
    ASSERT_EQ(list.popFront(), 2);
    ASSERT_EQ(list.popFront(), 1);
    ASSERT_EQ(list.popFront(), 0);
    ASSERT_EQ(list.popFront(), 10);
}

TEST(List, mergeList)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.merge(l);

    ASSERT_EQ(list.popBack(), 2);
    ASSERT_EQ(list.popBack(), 1);
    ASSERT_EQ(list.popBack(), 0);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, mergeData)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list.merge(0);

    ASSERT_EQ(list.popBack(), 0);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, plusList)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    auto listRes = list + l;

    ASSERT_EQ(listRes.popBack(), 2);
    ASSERT_EQ(listRes.popBack(), 1);
    ASSERT_EQ(listRes.popBack(), 0);
    ASSERT_EQ(listRes.popBack(), 15);
    ASSERT_EQ(listRes.popBack(), 10);
}

TEST(List, plusData)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    auto listRes = list +0;

    ASSERT_EQ(listRes.popBack(), 0);
    ASSERT_EQ(listRes.popBack(), 15);
    ASSERT_EQ(listRes.popBack(), 10);
}

TEST(List, plusEqualList)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list += l;

    ASSERT_EQ(list.popBack(), 2);
    ASSERT_EQ(list.popBack(), 1);
    ASSERT_EQ(list.popBack(), 0);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, plusEqualData)
{
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list += 0;

    ASSERT_EQ(list.popBack(), 0);
    ASSERT_EQ(list.popBack(), 15);
    ASSERT_EQ(list.popBack(), 10);
}

TEST(List, EqualList)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list += l;

    ASSERT_EQ(list == l, false);
    ASSERT_EQ(list == list, true);
}

TEST(List, notEqualList)
{
    denis::list<int> l {0, 1, 2};
    auto list = denis::list<int>();
    list.pushBack(10);
    list.pushBack(15);
    list += l;

    ASSERT_EQ(list != l, true);
    ASSERT_EQ(list != list, false);
}