#ifndef MYFORWARDLIST_H
#define MYFORWARDLIST_H

#include <iostream>

template<typename T>
struct MyForwardListItem {
    T value;
    MyForwardListItem<T> *nextItem = nullptr;
};

template<typename T>
class MyForwardList
{
    public:
        MyForwardList();
        virtual ~MyForwardList();
        void my_push_back(T value);
        void my_push_front(T value);
        MyForwardListItem<T> * getFirstItem();

    protected:

    private:
        int size;
        MyForwardListItem<T> *firstItem;
        MyForwardListItem<T> *lastItem;
};

template<typename T>
MyForwardList<T>::MyForwardList()
{
    firstItem = nullptr;
    lastItem = firstItem;
    size = 0;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
MyForwardList<T>::~MyForwardList()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete firstItem;
}

template<typename T>
void MyForwardList<T>::my_push_back(T value)
{
    MyForwardListItem<T> *newItem = new MyForwardListItem<T>;
    newItem->nextItem = nullptr;

    if (firstItem == nullptr) {
        newItem->value = value;
        ++size;
        firstItem = newItem;
        lastItem = newItem;
        return;
    }
    lastItem->nextItem = newItem;
    lastItem = newItem;
    newItem->value = value;
    ++size;
}

template<typename T>
void MyForwardList<T>::my_push_front(T value)
{
    MyForwardListItem<T> *newItem = new MyForwardListItem<T>;
    newItem->nextItem = firstItem;
    firstItem = newItem;
    newItem->value = value;
    ++size;
}

template<typename T>
MyForwardListItem<T> * MyForwardList<T>::getFirstItem()
{
    return firstItem;
}

#endif // MYFORWARDLIST_H
