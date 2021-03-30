#include "MyOwnException.h"

#ifndef LW2_4_MYEXCEPTION_H
#define LW2_4_MYEXCEPTION_H

class MyException
{
private:
    int* a;
    size_t size;

public:
    MyException() : a(nullptr), size(0)
    {
        a = new int[1];
        a[0] = '\0';
    };

    void push_index(int element, int index)
    {
        if ((index > size - 1) || (index < 0))
            throw MyOwnException("Invalid index.");
        else
        {
            ++size;
            int* part = new int[size];
            for (int i = 0; i < index; ++i)
                part[i] = a[i];
            part[index] = element;

            for (int i = index + 1; i < size - 1; ++i)
                part[i] = a[i - 1];

            a = new int[size];
            for (int i = 0; i < size; ++i)
                a[i] = part[i];

            delete[] part;
        }
    }


    void push_back(int element)
    {
        ++size;
        int* other = new int[size];
        for (int i = 0; i < size - 1; ++i)
            other[i] = a[i];
        other[size - 1] = element;

        a = new int[size];
        for (int i = 0; i < size; ++i)
            a[i] = other[i];

        delete[] other;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
            std::cout << a[i] << ' ';
        std::cout << std::endl;
    }


};

#endif //LW2_4_MYEXCEPTION_H
