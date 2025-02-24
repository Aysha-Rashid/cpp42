#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include "data.hpp"
#include <stdint.h>
#include <iostream>

// #include <cstdint>

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer &copy);
        Serializer operator=(Serializer &copy);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};
#endif