#include <iostream>

#include "inc/List.hpp"
#include <vector>

void print_list(denis::list<int> &inList)
{
    for (auto iterator = inList.cbegin(); iterator != inList.cend(); iterator.next())
    {
        std::cout << (*iterator).get() << " ";
    }
}

int main()
{
    setbuf(stdout, NULL);

    // Тест кострукторов
    std::cout << "Constructor 1 test: ";
    denis::list<int> list1;
    list1.pushBack(10);
    print_list(list1);

    std::cout << "\nConstructor 2 test: ";
    denis::list<int> list2;

    std::cout << "\nConstructor 3 test: ";
    int arr[] = { 5, 4, 3, 2, 1 };
    denis::list<int> list3(arr, 5);
    print_list(list3);

    std::cout << "\nConstructor 4 test: ";
    denis::list<int> list4(list3);
    print_list(list4);

    std::cout << "\nConstructor 5 test: ";
    denis::list<int> list5 = { 5, 4, 3, 2, 1 };
    print_list(list5);

    std::cout << "\nConstructor 6 test: ";
    auto fst = list3.begin();
    auto end = list3.begin() + 4;
    std::vector<int> vec228 = { 1, 2, 3, 4 };
    auto fs1 = vec228.begin() + 2;

    denis::list<int> list6 = { 7, 7, 7 };



    // Тест push_front методов
    std::cout << "\nPush front by value: ";
    auto iterator = list6.pushFront(6);

    while (iterator != list6.end())
    {
        std::cout << " " << (*iterator).get();
        iterator++;
    }

    print_list(list6);

    std::cout << "\nPush front by denis::list (list3): ";
    list6.pushFront(list3);
    print_list(list6);

    // Тест insert методов
    denis::list<int> list7 = { 1, 2, 3 };

    std::cout << "\nInsert value to 1st pos: ";
    list7.insert(list7.begin() + 1, 4);
    print_list(list7);

    std::cout << "\nInsert denis::list (list3) to 2nd pos: ";
    list7.insert(list7.begin() + 2, list3);
    print_list(list7);

    std::cout << "\nInsert (const interator) value to 1st pos: ";
    list7.insert(list7.cbegin() + 1, 4);
    print_list(list7);

    std::cout << "\nInsert (const iterator) denis::list (list3) to 2nd pos: ";
    list7.insert(list7.cbegin() + 2, list3);
    print_list(list7);

    // Test push_back методов
    denis::list<int> list8 = { 1, 2, 3 };
    std::cout << "\nPush back by value: ";
    list8.pushBack(4);
    print_list(list8);

    std::cout << "\nPush back by denis::list (list3): ";
    list8.pushBack(list3);
    print_list(list8);

    // Тест pop методов
    std::cout << "\nPop front (list8): ";
    list8.popFront();
    print_list(list8);

    std::cout << "\nPop back (list8): ";
    list8.popBack();
    print_list(list8);

    std::cout << "\nRemove by iterator (pos 2): ";
    list8.remove(list8.begin() + 2);
    print_list(list8);

    // Тест reverse
    std::cout << "\nReverse denis::list (list3): ";
    list3.reverse();
    print_list(list3);

    // Тест операторов

    denis::list<int> list9 = { 1, 2, 3 };
    denis::list<int> list10 = { 1, 2, 3 };

    std::cout << "\nTest == operator: ";
    if (list9 == list10)
    {
        std::cout << "done";
    }
    else
    {
        std::cout << "failed";
    }

    list9.popBack();

    std::cout << "\nTest != operator: ";
    if (list9 != list10)
    {
        std::cout << "done";
    }
    else
    {
        std::cout << "failed";
    }

    std::cout << "\nTest = operator: ";
    list9 = list10;
    print_list(list9);

    std::cout << "\nTest += operator: ";
    list9 += list10;
    list9 += 25;
    print_list(list9);

    std::cout << "\nTest + operator: ";
    list9 = list10 + list8 + list9;
    list9 += 777;
    print_list(list9);

    // Тест итераторов
    std::cout << "\nTest iterators: ";
    auto iterator1 = list9.begin();
    //*iterator1 = 500;
    //*(++iterator1 + 1) = 400;
    print_list(list9);

    std::cout << "\nTest constant iterators: ";
    auto iterator2 = list9.cbegin();
    // *iterator2 = 522; - не должно работать
    ++iterator2;
    auto iterator3 = list9.cend();

    while (++iterator2 != iterator3)
    {
        std::cout << (*iterator2).get() << " ";
    }

    denis::list<int> list11 = { 1, 2, 3 };
    denis::list<int> list12 = { 4, 5, 6 };

    // Тест merge метода
    std::cout << "\nMerge test: ";
    list12.merge(list11);
    list12.merge(505);
    print_list(list12);

    // Тест bool оператора
    std::cout << "\nBool operators test (not constant): ";
    if (list11.begin())
    {
        std::cout << "test1 done ";
    }
    else
    {
        std::cout << "test1 fail ";
    }

    if (list11.end())
    {
        std::cout << "test2 fail";
    }
    else
    {
        std::cout << "test2 done";
    }

    std::cout << "\nBool operators test (constant): ";
    if (list11.cbegin())
    {
        std::cout << "test1 done ";
    }
    else
    {
        std::cout << "test1 fail ";
    }

    if (list11.cend())
    {
        std::cout << "test2 fail";
    }
    else
    {
        std::cout << "test2 done";
    }

    return 0;
}
