#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
size_t Array<T>::size() const
{
    return this->_size;
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0)
{
    this->_size = other._size;
    if (this->_size > 0)
    {
        this->_array = new T[this->_size];
        for (size_t i = 0; i < this->_size; ++i)
            this->_array[i] = other._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] this->_array;
        this->_size = other._size;
        this->_array = (this->_size > 0) ? new T[this->_size] : NULL;
        for (size_t i = 0; i < this->_size; ++i)
            this->_array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || static_cast<size_t>(index) >= this->_size)
        throw std::out_of_range("Index out of bounds");
    return this->_array[index];
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_array;
}
