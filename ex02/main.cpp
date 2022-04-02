#include <iostream>
#include <cstdlib>
#include <ctime>

struct Base
{
    virtual ~Base() {}
};

struct A : public Base {};
struct B : public Base {};
struct C : public Base {};

Base* generate()
{
    switch (std::rand() % 3)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    default:
        return new C();
    }
}

void identify(Base* ptr)
{
    if (dynamic_cast<A*>(ptr))
        std::cout << "A";
    if (dynamic_cast<B*>(ptr))
        std::cout << "B";
    if (dynamic_cast<C*>(ptr))
        std::cout << "C";
}

void identify(Base& ref)
{
    try
    {
        dynamic_cast<A&>(ref);
        std::cout << "A";
    } catch(std::exception&) {}
    try
    {
        dynamic_cast<B&>(ref);
        std::cout << "B";
    } catch(std::exception&) {}
    try
    {
        dynamic_cast<C&>(ref);
        std::cout << "C";
    } catch(std::exception&) {}
}

int main()
{
    std::srand(std::time(NULL));

    Base* obj = generate();

    identify(obj);
    identify(*obj);

    std::cout << std::endl;

    delete obj;
}
