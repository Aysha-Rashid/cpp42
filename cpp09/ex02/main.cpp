#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe arg;
    try
    {
        if (argc < 2)
            throw (std::runtime_error("invalid arguments"));
        arg.parseInput(argv, argc);
        arg.MergeAndSort();
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    arg.clearNumbers();
}
