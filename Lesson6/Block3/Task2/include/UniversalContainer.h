#ifndef UNIVERSALCONTAINER_H
#define UNIVERSALCONTAINER_H

template <typename T>
class UniversalContainer
{
    public:
        UniversalContainer();
        virtual ~UniversalContainer();
        void push(T value);
        int getValuesQuantity();
        T pop();
        T front();

        T& operator [] (int index)
        {
            if (index < values_quantity) {
                return data[index];
            }
            else {
                // TODO raise an Exception.
                std::cout << "There isn't element with " << index << " index in container!!!" << std::endl;
            }
        }

        friend std::ostream& operator << (std::ostream &s, const UniversalContainer &value)
        {
            s << "!!!! Preaty output for parameters: " << value << std::endl;
            return s;
        }

    protected:

    private:
        int values_quantity = 0;
        int default_values_quantity = 5;
        // TODO update for resize and deleting empty values
        T *data;
};

template <typename T>
UniversalContainer<T>::UniversalContainer()
{
    data = new T[default_values_quantity];
}

template <typename T>
UniversalContainer<T>::~UniversalContainer()
{
    delete data;
}

// Add value to the end of container
template <typename T>
void UniversalContainer<T>::push(T value)
{
    if (values_quantity < default_values_quantity) {
        *(data + values_quantity) = value;
        values_quantity++;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    else {
        std::cout << "The container is full! Use pop() method to free up container resources.";
    };
}

template <typename T>
int UniversalContainer<T>::getValuesQuantity() {
    return values_quantity;
}

// Return last value in container (should also delete it but it in TODO list)
template <typename T>
T UniversalContainer<T>::pop()
{
    if (values_quantity > 0) {
        T temp = *(data + values_quantity);
        values_quantity--;
        // Replace last value with empty T value or really delete this value to avoid access to it after using pop()
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return temp;
    }
    else {
        // TODO return empty T value
        std::cout << "The container is empty! Use push() method to add values in container.";
    };
}

// Just return the first value in container (without deleting it).
template <typename T>
T UniversalContainer<T>::front()
{
    if (values_quantity > 0) {
        T temp = *data;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return temp;
    }
    else {
        // TODO return empty T value
        std::cout << "The container is empty! Use push() method to add values in container.";
    };
}


// create Univeraal container for only double values (bool specialization of template)
template <>
class UniversalContainer<bool>
{
    public:
        UniversalContainer();
        virtual ~UniversalContainer();

        double& operator [] (int index)
        {
            return data[index];
        }

        friend std::ostream& operator << (std::ostream &s, const UniversalContainer &value)
        {
            s << "!!!! Preaty output for parameters (bool template container): " << value << std::endl;
            return s;
        }

    protected:

    private:
        // TODO update for resize and deleting empty values
        double *data;
};


#endif // UNIVERSALCONTAINER_H
