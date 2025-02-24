#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
template <typename T>
class Array
{
    private:
        T* _array;
        size_t _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](int index);
        ~Array();
        size_t size() const;
};
#include "Array.tpp"
