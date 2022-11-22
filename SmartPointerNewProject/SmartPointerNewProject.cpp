#include <iostream>
#include "IntArr.h"
#include "SmartPointer.h"

using namespace std;

class Name
{
    string name;
public:
    Name(string name) : name{ name } 
    {
        cout << "origin constructor\n";
    }
    Name(Name& name) = delete;
    Name& operator=(Name& name) = delete;

    friend void swap(Name& a, Name& b) noexcept
    {
        std::swap(a.name, b.name);
    }

    Name(Name&& name)
    {
        cout << "move constructor\n";
        swap(*this, name);
    }

    Name& operator=(Name&& name)
    {
        cout << "move assign\n";
        swap(*this, name);
        return *this;
    }
    const string& GetName() { return name; }
};


int main()
{
    /*IntArr arr1(20);
    IntArr arr2;

    std::cout << "assign lvalue: \n";
    arr2 = IntArr(10);
    std::cout << "end assign lvalue: \n";*/

    //int&& a = 10;
    //IntArr arr(CreateArr());

    Name name1{ "Bob" };
    name1 = Name{ "Leo" };

    cout << name1.GetName();

}
