#pragma once
#include <list>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        ~MutantStack();

        typedef typename Container::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp" 