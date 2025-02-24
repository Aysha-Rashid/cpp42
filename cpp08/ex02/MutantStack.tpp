#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
    std::cout << "Constructor being called here " << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
    std::cout << "Deconstructor being called here " << std::endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}
