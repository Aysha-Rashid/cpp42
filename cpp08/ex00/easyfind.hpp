#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

template <typename T>
void easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        std::cout << "Found it: " << *it << std::endl;
    else
        throw std::runtime_error("Value not found in container");
}
