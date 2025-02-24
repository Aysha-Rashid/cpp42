#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::cout << "     the iterable stack : " << std::endl; 
    std::cout << " \n";
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator stack_it = mstack.begin();
    MutantStack<int>::iterator stack_ite = mstack.end();
    ++stack_it;
    --stack_it;
    if (mstack.empty())
    {
        std::cout << "The stack is empty!!" << std::endl;
        return 1;
    }
    while (stack_it != stack_ite)
    {
        std::cout << "inside the stack : " << *stack_it << std::endl;
        ++stack_it;
    }
    std::cout << "Using std::find to locate 737:" << std::endl;
    MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 737);
    if (found != mstack.end()) {
        std::cout << "Found: " << *found << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    std::cout << "Size before adding 1000 elements: " << mstack.size() << std::endl;
     std::cout << "Testing with large data set..." << std::endl;
    for (int i = 0; i < 1000; ++i) {
        mstack.push(i);
    }
    std::cout << "Size after adding 1000 elements: " << mstack.size() << std::endl;
    std::stack<int > s(mstack);
    return 0;
}