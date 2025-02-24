#pragma once
#include "iostream"

template <typename T2>
void printString(T2 print) {
    std::cout << print << std::endl;
}

template <typename T1, typename F>
void iter(T1 *address, size_t length, F printString)
{
    for (size_t i = 0; i < length; i++)
        printString(address[i]);
};
