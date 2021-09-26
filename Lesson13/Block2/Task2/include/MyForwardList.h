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
        void deleteFirstItem();
        void showItem(int index);
        int getSize();
        void printAllItems();

        MyForwardListItem<T>& operator[](int index)
        {
            if ((index < 0) || (index >= size)) {
                std::cout << "Index out of range. Current index might be from ";
                std::cout << " 0 to " << size - 1 << ". You have index = " << index << std::endl;
                throw 1;
            }

            MyForwardListItem<T> *tmp = firstItem;
            if (index == 0) {
                return *tmp;
            }
            while (index != 0) {
                tmp = tmp->nextItem;
                --index;
            }
            return *tmp;
        }



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

template<typename T>
void MyForwardList<T>::deleteFirstItem()
{
    if (size > 1) {
        MyForwardListItem<T> *tmp = firstItem->nextItem;
        delete firstItem;
        firstItem = tmp;
    }
    else if (size == 1) {
        delete firstItem;
        firstItem = nullptr;
        lastItem = nullptr;
    }
    else {
        std::cout << "There aren't any elements!" << std::endl;
        return;
    }

    --size;
}

template<typename T>
void MyForwardList<T>::showItem(int index)
{
    if ((index < 0) || (index >= size)) {
        std::cout << "Index out of range. Current index might be from ";
        std::cout << " 0 to " << size - 1 << ". You have index = " << index << std::endl;
        return;
    }
    std::cout << "Element with index " << index << " is " << (*this)[index].value << std::endl;;
}

template<typename T>
int MyForwardList<T>::getSize()
{
    return size;
}

template<typename T>
void MyForwardList<T>::printAllItems()
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
#endif // MYFORWARDLIST_H
