#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer constructed" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    std::cout << "Serializer copied" << std::endl;
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    std::cout << "Serializer assigned" << std::endl;
    if (this != &other) {
        // copy fields here
    }
    return *this;
}

Serializer::~Serializer() {
    std::cout << "Serializer destructed" << std::endl;
}
	

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
