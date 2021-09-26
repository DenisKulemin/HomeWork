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
    delete data;
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
void MyVector<T>::my_push_back(T value)
{
    if (firstAvailableItemIndex == size - 1) {
        this->my_resize();
    };

    data[firstAvailableItemIndex] = value;
    ++firstAvailableItemIndex;
}

template<typename T>
void MyVector<T>::printAllItems()
{
    for (int i = 0; i < firstAvailableItemIndex; ++i) {
        std::cout << data[i] << std::endl;
    }
}

#endif // MYVECTOR_H
