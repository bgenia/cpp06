#include <iostream>
#include <string>

typedef unsigned long uintptr_t;

struct Data
{
    std::string name;
    int value;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data data = {"Aboba", 10};

    std::cout << data.name << ": " << data.value << std::endl;

    uintptr_t raw = serialize(&data);

    Data* ptr = deserialize(raw);

    std::cout << ptr->name << ": " << ptr->value << std::endl;
}
