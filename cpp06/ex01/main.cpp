#include <iostream>
#include <string>
#include "Serializer.hpp"

int main()
{
    Data originalData = {42, "Test Object"};
    Data *originalPtr = &originalData;

    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data *deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Address of originalPtr : " << originalPtr << std::endl;
    std::cout << "Address of deserializedPtr : " << deserializedPtr << std::endl;
    if (originalPtr == deserializedPtr) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data ID: " << deserializedPtr->id << ", Name: " << deserializedPtr->name << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }
    return 0;
}
