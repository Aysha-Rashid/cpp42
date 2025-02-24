#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"


int main()
{
    Base *hello = NULL;
    Base *test = NULL;
    hello = hello->generate();
    hello->identify(hello);
    hello->identify(*hello);
    hello->identify(test);
    delete hello;
}