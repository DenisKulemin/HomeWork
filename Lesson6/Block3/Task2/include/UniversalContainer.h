#ifndef UNIVERSALCONTAINER_H
#define UNIVERSALCONTAINER_H

template <typename T>
class UniversalContainer
{
    public:
        UniversalContainer();
        virtual ~UniversalContainer();

        T& operator [] (int index)
        {
            return data[index];
        }

        friend std::ostream& operator << (std::ostream &s, const UniversalContainer &value)
        {
            s << "!!!! Preaty output for parameters: " << value << std::endl;
            return s;
        }

    protected:

    private:
        // TODO update for resize and deleting empty values
        T *data;
};

#endif // UNIVERSALCONTAINER_H

template <typename T>
UniversalContainer<T>::UniversalContainer()
{
    data = new T[5];
}

template <typename T>
UniversalContainer<T>::~UniversalContainer()
{
    delete data;
}
