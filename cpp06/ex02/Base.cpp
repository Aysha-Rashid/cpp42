#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << "Base Destructor called" << std::endl;
}

Base *Base::generate(void)
{
    int success;
    srand((unsigned) time(NULL));
    success = rand() % 3;
    if (success == 0)
    {
        std::cout << "Creating A" << std::endl;
        return (new A);
    }
    else if (success == 1)
    {
        std::cout << "Creating B" << std::endl;
        return (new B);
    }
    else
    {
        std::cout << "Creating c" << std::endl;
        return (new C);
    }
    return (this);
}

void Base:: identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The pointer type of Base is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The pointer type of Base is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The pointer type of Base is C" << std::endl;
    else
        std::cout << "The pointer type of Base is invalid" << std::endl;
}

void Base::identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "The reference type of Base is A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "The reference type of Base is B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "The reference type of Base is C" << std::endl;
    } catch (...) {}
}
