#include <iostream>
#pragma once
class IntArr
{
    int size;
    int* array;

    void Log(const char* cstr)
    {
        std::cout << "[" << this << "] " << cstr << "\n";
    }
public:
    explicit IntArr(int size = 0) : size{ size }, array{ new int[size] }
    {
        Log("Constructor");
    }
    ~IntArr()
    {
        Log("Destructor");
        if (array)
        {
            delete[] array;
            size = 0;
        }
    }

    // copy constructor
    IntArr(const IntArr& other) : size{ other.size }, array{ new int[size] }
    {
        Log("Copy Constructor");
        for (int i = 0; i < size; i++)
            array[i] = other.array[i];
    }

    // move constructor
    IntArr(IntArr&& other) noexcept : size{ other.size }, array{ other.array }
    {
        Log("Move Constructor");
    }

    // copy assigment
    IntArr& operator=(const IntArr& other)
    {
        Log("Copy Assimend Operator");
        IntArr temp(other);
        std::swap(size, temp.size);
        std::swap(array, temp.array);

        return *this;
    }

    // move assigment
    IntArr& operator=(IntArr&& other)
    {
        Log("Move Assimend Operator");
        std::swap(size, other.size);
        std::swap(array, other.array);
        return *this;
    }

};
