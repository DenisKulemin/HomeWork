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
        void deleteFirstItem();
        void deleteLastItem();
        void sortComb();
        void showItem(int index);

        MyListItem<T>& operator[](int index)
        {
            if ((index < 0) || (index >= size)) {
                std::cout << "Index out of range. Current index might be from ";
                std::cout << " 0 to " << size - 1 << ". You have index = " << index << std::endl;
                throw 1;
            }
            MyListItem<T> *tmp = nullptr;
            if (index < size / 2) {
                tmp = firstItem;
                if (index == 0) {
                    return *tmp;
                }
                while (index != 0) {
                    tmp = tmp->nextItem;
                    --index;
                }
            }
            else {
                tmp = lastItem;
                if (index == size - 1) {
                    return *tmp;
                }
                index = size - 1 - index;
                while (index != 0) {
                    tmp = tmp->previousItem;
                    --index;
                }
            }
            return *tmp;
        }

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

template<typename T>
void MyList<T>::deleteFirstItem()
{
    if (size > 1) {
        MyListItem<T> *tmp = firstItem->nextItem;
        delete firstItem;
        tmp->previousItem = nullptr;
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
void MyList<T>::deleteLastItem()
{
    if (size > 2) {
        MyListItem<T> *tmp = &((*this)[size - 2]);
        delete lastItem;
        tmp->nextItem = nullptr;
        lastItem = tmp;
    }
    else if (size == 2) {
        delete lastItem;
        firstItem->nextItem = nullptr;
        lastItem = firstItem;
    }
    else if (size == 1){
        delete lastItem;
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
void MyList<T>::showItem(int index)
{
    if (size == 0) {
        std::cout << "The list is empty!" << std::endl;
        return;
    }
    if ((index < 0) || (index >= size)) {
        std::cout << "Index out of range. Current index might be from ";
        std::cout << " 0 to " << size - 1 << ". You have index = " << index << std::endl;
        return;
    }
    std::cout << "Element with index " << index << " is " << (*this)[index].value << std::endl;;
}

template<typename T>
void MyList<T>::sortComb()
{
    if (size < 2) {
        return;
    }
    // k - coefficient that help to reduce number of checked values in every cycly
    double k = 1.247;
    double step = size - 1;
    while (step >= 1) {
        for (int i = 0; i + step < size; ++i) {

            if ((*this)[i].value > (*this)[i + step].value) {
                T tmp = (*this)[i].value;
                (*this)[i].value = (*this)[i + step].value;
                (*this)[i + step].value = tmp;
            }
        }
        step /= k;
    }
}
#endif // MYLIST_H
