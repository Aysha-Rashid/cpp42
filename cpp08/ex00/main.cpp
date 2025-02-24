#include "easyfind.hpp"

int main()
{
    try
    {
        std::array<int, 6> vec; // need to state the size of the array
        std::cout << "array : " <<std::endl;
        vec[0] = 1;
        vec[1] = 2;
        vec[2] = 3;
        vec[3] = 4;
        vec[4] = 5;
        std::cout << vec[0] << std::endl;
        std::cout << vec[1] << std::endl;
        std::cout << vec[2] << std::endl;
        std::cout << vec[3] << std::endl;
        std::cout << vec[4] << std::endl;
        easyfind(vec, 3); // Found
        easyfind(vec, 6); // Throws exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << " for arrays" << std::endl;
    }
    try
    {

        std::vector<int> vec; // can allocate the space dynamically
        std::cout << "vector : " <<std::endl;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::cout << vec[0] << std::endl;
        std::cout << vec[1] << std::endl;
        std::cout << vec[2] << std::endl;
        std::cout << vec[3] << std::endl;
        std::cout << vec[4] << std::endl;
        easyfind(vec, 3); // Found
        easyfind(vec, 6); // Throws exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << " for vectors" << std::endl;
    }

    return 0;
}
