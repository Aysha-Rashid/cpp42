#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    try {
        Span sp(20000);

        std::cout << "Adding individual numbers to Span..." << std::endl;
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(1);
        sp.addNumber(11);

        int array[] = {7, 8, 9, 10};
        std::vector<int> vec(array, array + sizeof(array) / sizeof(array[0]));
        std::cout << "Adding numbers from a vector..." << std::endl;
        sp.addNumber(vec.begin(), vec.end());

        std::list<int> list;
        for (int i = 0; i < 10000; i++) {
            list.push_back(std::rand() % 10000);
        }
        std::cout << "Adding random numbers from a list..." << std::endl;
        sp.addNumber(list.begin(), list.end());

        std::cout << "Calculating spans..." << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::cout << "\nTesting edge cases:" << std::endl;
        Span smallSpan(2);
        smallSpan.addNumber(5);
        smallSpan.addNumber(10);
        std::cout << "Small Span Shortest: " << smallSpan.shortestSpan() << std::endl;
        std::cout << "Small Span Longest: " << smallSpan.longestSpan() << std::endl;

        try {
            std::cout << "Testing exception: Adding to a full Span..." << std::endl;
            smallSpan.addNumber(20); // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        try {
            std::cout << "Testing exception: Calculating span with insufficient numbers..." << std::endl;
            Span emptySpan(1);
            emptySpan.shortestSpan(); // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
