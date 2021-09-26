#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

template<typename T>
class MyVector
{
    public:
        MyVector();
        virtual ~MyVector();
        void my_push_back(T value);
        void my_resize();
        void printAllItems();
        void sortComb();
        void deleteFirstItem();
        void deleteLastItem();
        void insertItem(T value, int index);
        void deleteItem(int index);
        int getFirstAvailableItemIndex();
        void sortBubble();
        void erase();

        T& operator[](int index)
        {
            if ((index < 0) || (index >= size)) {
                std::cout << "Index out of range. Current index might be from ";
                std::cout << " 0 to " << size - 1 << ". You have index = " << index << std::endl;
                throw 1;
            }
            return data[index];
        }

    protected:

    private:
        int size;
        int firstAvailableItemIndex;
        T *data;
};

template<typename T>
MyVector<T>::MyVector()
{
    size = 1;
    firstAvailableItemIndex = 0;
    data = new T[size];
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete [] data;
}

template<typename T>
void MyVector<T>::my_push_back(T value)
{
    if (firstAvailableItemIndex == size - 1) {
        this->my_resize();
    };

    data[firstAvailableItemIndex] = value;
    ++firstAvailableItemIndex;
}

template<typename T>
void MyVector<T>::my_resize()
{
    int new_size = 2 * size;
    T *tmp = new T[new_size];
    for (int i = 0; i < size; ++i) {
        tmp[i] = data[i];
    }
    size = new_size;
    delete data;
    data = tmp;
}

template<typename T>
void MyVector<T>::printAllItems()
{
    for (int i = 0; i < firstAvailableItemIndex; ++i) {
//        std::cout << data[i] << std::endl;
        std::cout << data[i] << " ";
    }
}

template<typename T>
void MyVector<T>::sortComb()
{
    if (firstAvailableItemIndex < 2) {
        return;
    }
    // k - coefficient that help to reduce number of checked values in every cycly
    double k = 1.247;
    double step = firstAvailableItemIndex - 1;
    while (step >= 1) {
        for (int i = 0; i + step < firstAvailableItemIndex; ++i) {
            int nextIndex = static_cast<int>(i + step);
            if (data[i] > data[nextIndex]) {
                T tmp = data[i];
                data[i] = data[nextIndex];
                data[nextIndex] = tmp;
            }
        }
        step /= k;
    }
}

template<typename T>
void MyVector<T>::deleteFirstItem()
{
    if (firstAvailableItemIndex > 0) {
        for (int i = 1; i < firstAvailableItemIndex; ++i) {
            data[i - 1] = data[i];
        }
        --firstAvailableItemIndex;
    }
    else {
        std::cout << "There aren't any elements!" << std::endl;
    }
}

template<typename T>
void MyVector<T>::deleteLastItem()
{
    if (firstAvailableItemIndex > 0) {
        --firstAvailableItemIndex;
    }
    else {
        std::cout << "There aren't any elements!" << std::endl;
    }
}

template<typename T>
void MyVector<T>::insertItem(T value, int index)
{
    if ((index < 0) || (index > firstAvailableItemIndex)) {
        std::cout << "Index out of range. Current index might be from ";
        std::cout << " 0 to " << firstAvailableItemIndex << ". You have index = " << index << std::endl;
        return;
    }
    if (index == firstAvailableItemIndex) {
        this->my_push_back(value);
        return;
    }

    if (firstAvailableItemIndex == size - 1) {
        my_resize();
    }
    for (int i = firstAvailableItemIndex; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++firstAvailableItemIndex;
}

template<typename T>
void MyVector<T>::deleteItem(int index)
{
    if (firstAvailableItemIndex <= 0) {
        std::cout << "There is an empty list. Nothing to delete!" << std::endl;
        return;
    }
    if ((index < 0) || (index >= firstAvailableItemIndex)) {
        std::cout << "Index out of range. Current index might be from ";
        std::cout << " 0 to " << firstAvailableItemIndex - 1 << ". You have index = " << index << std::endl;
        return;
    }

    if (index == firstAvailableItemIndex - 1) {
        this->deleteLastItem();
        return;
    }
    else if (index == 0) {
        this->deleteFirstItem();
        return;
    }

    for (int i = index; i < firstAvailableItemIndex - 1; ++i) {
        data[i] = data[i + 1];
    }
    --firstAvailableItemIndex;
}

template<typename T>
int MyVector<T>::getFirstAvailableItemIndex()
{
    return firstAvailableItemIndex;
}

template<typename T>
void MyVector<T>::sortBubble()
{
    for (int i = 0; i < firstAvailableItemIndex; ++i) {
        for (int j = 0; j + 1 < firstAvailableItemIndex - i; ++j) {
            if (data[j + 1] < data[j]) {
                T tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

template<typename T>
void MyVector<T>::erase()
{
    firstAvailableItemIndex = 0;
}

#endif // MYVECTOR_H
