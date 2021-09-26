#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

template<typename T>
struct MyListItem {
    T value;
    MyListItem<T> *nextItem = nullptr;
    MyListItem<T> *previousItem = nullptr;
};

template<typename T>
class MyList
{
    public:
        MyList();
        virtual ~MyList();
        void my_push_back(T value);
        void my_push_front(T value);
        MyListItem<T> * getFirstItem();
        void printAllItems();

    protected:

    private:
        int size;
        MyListItem<T> *firstItem;
        MyListItem<T> *lastItem;
};

template<typename T>
MyList<T>::MyList()
{
    firstItem = nullptr;
    lastItem = firstItem;
    size = 0;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
MyList<T>::~MyList()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete firstItem;
}

template<typename T>
MyListItem<T> * MyList<T>::getFirstItem()
{
    return firstItem;
}

template<typename T>
void MyList<T>::my_push_back(T value)
{
    MyListItem<T> *newItem = new MyListItem<T>;
    newItem->nextItem = nullptr;

    if (firstItem == nullptr) {
        newItem->value = value;
        ++size;
        firstItem = newItem;
        lastItem = newItem;
        return;
    }
    newItem->previousItem = lastItem;
    lastItem->nextItem = newItem;
    lastItem = newItem;
    newItem->value = value;
    ++size;
}

template<typename T>
void MyList<T>::my_push_front(T value)
{
    MyListItem<T> *newItem = new MyListItem<T>;
    newItem->nextItem = firstItem;
    if (firstItem == nullptr) {
        newItem->value = value;
        ++size;
        firstItem = newItem;
        lastItem = newItem;
        return;
    }
    firstItem->previousItem = newItem;
    firstItem = newItem;
    newItem->value = value;
    ++size;
}

template<typename T>
void MyList<T>::printAllItems()
{
    std::cout << "Size " << size << std::endl;
    if (firstItem == nullptr) {
        std::cout << "There aren't any elements!" << std::endl;
    }
    else {
        for (auto i = firstItem; i->nextItem != nullptr; i = i->nextItem) {
            std::cout << i->value << std::endl;
        }
        std::cout << lastItem->value << std::endl;
    }
}

#endif // MYLIST_H
