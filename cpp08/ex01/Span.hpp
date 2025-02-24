#pragma once

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

class Span
{
    private:
        unsigned int max;
        std::vector<int> _numbers;
    public:
        Span(unsigned int N);
        Span(const Span &copy);
        Span& operator=(const Span &copy);
        ~Span();

        void addNumber(unsigned int number);
        template <typename T>
        void addNumber(T firstRange, T lastRange) {
            size_t rangeSize = std::distance(firstRange, lastRange);
            if (rangeSize + _numbers.size() > max)
                throw std::runtime_error("Max size exceeded");
            _numbers.insert(_numbers.end(), firstRange, lastRange);
        }
        int shortestSpan() const;
        int longestSpan() const;
        void printNumber();
};
