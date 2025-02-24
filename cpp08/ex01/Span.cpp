#include "Span.hpp"

Span::Span(unsigned int N) : max(N) {
    std::cout << "Span Constructor Called" << std::endl;
}

Span::Span(const Span &copy) : max(0) {
    this->max = copy.max;
    std::cout << "Copy Span Constructor Called" << std::endl;
}

Span &Span::operator=(const Span &copy)
{
    this->max = copy.max;
    std::cout << "Copy Assignment Span Constructor Called" << std::endl;
    return (*this);
}

Span::~Span() {
    std::cout << "Span Destructor Called" << std::endl;
}

void Span::addNumber(unsigned int number) {
    if (this->_numbers.size() >= max)
        throw std::runtime_error("Max Size reached");
    this->_numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (this->_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate a span");

    std::vector<int> sortedNumbers = this->_numbers;
    sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = std::numeric_limits<int>::max();
    std::vector<int>::iterator it = sortedNumbers.begin();
    std::vector<int>::iterator nextIt = it;
    ++nextIt;

    for (; nextIt != sortedNumbers.end(); it++, nextIt++) { 
        int span = std::abs(*nextIt - *it);
        shortest = std::min(shortest, span);
    }
    return (shortest);
}

int Span::longestSpan() const
{
    if (this->_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate a span");

    int minVal = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    int maxVal = *std::max_element(this->_numbers.begin(), this->_numbers.end());

    return (maxVal - minVal);
}

void Span::printNumber()
{
    for (std::vector<int>::iterator it = this->_numbers.begin(); it != this->_numbers.end(); it++)
        std::cout << "element stored in sp is = " << *it << "\n"; 
}
