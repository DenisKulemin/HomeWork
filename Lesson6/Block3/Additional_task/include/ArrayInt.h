#ifndef ARRAYINT_H
#define ARRAYINT_H

template <typename T, int MaxSize>
class ArrayInt
{
    public:
        ArrayInt();

        virtual ~ArrayInt();
        void ClearArray();
        int GetArrayLenght();

        T& operator [] (int index)
        {
            return data[index];
        }

        friend std::ostream& operator << (std::ostream &s, const ArrayInt &value)
        {
            s << "!!!! Preaty output for parameters: " << value << std::endl;
            return s;
        }

    protected:

    private:
        int array_lenght;
        T *data;
};

#endif // ARRAYINT_H

template <typename T, int MaxSize>
ArrayInt<T, MaxSize>::ArrayInt()
{
    array_lenght = MaxSize;
    data = new T[MaxSize];
}

template <typename T, int MaxSize>
ArrayInt<T, MaxSize>::~ArrayInt()
{
    delete data;
}

template <typename T, int MaxSize>
void ArrayInt<T, MaxSize>::ClearArray()
{
    delete data;
    data = nullptr;
    array_lenght = 0;
}

template <typename T, int MaxSize>
int ArrayInt<T, MaxSize>::GetArrayLenght()
{
    return array_lenght;
}
