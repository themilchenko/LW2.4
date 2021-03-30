#include <iostream>
#include <string>
#include <vector>

#include "MyException.h"
#include "MyOwnException.h"

class Wrong_vec
{
private:
    std::vector<char*> vec;

public:
    void push_vec()
    {
        for (int i = 0; i < 10000; ++i)
            vec.push_back(new char);
    }
};

class Class1
{
public:
    virtual void foo() const { };
};

class Class2: public Class1
{
    virtual void foo() const { };
};

int recursion(int a)
{
    int* b = new int[1000000];
    return a * recursion(a + 1);
}


int main()
{

    /*==================================================================*/
    /*============================Task1=================================*/
    /*==================================================================*/

    /*std::out_of_range*/
    /*=================*/
    try
    {
        std::vector<int> vec({ 1, 2, 3, 4, 5 });
        vec.at(6) = 5;
    }
    catch(const std::out_of_range& error)
    {
        std::cerr << "Out of range: " << error.what() << std::endl;
    }
    /*=================*/

    /*std::lengh_error*/
    /*================*/
    try
    {
        std::string str = "Hello";
        str.resize(-1);
    }
    catch (const std::length_error& error)
    {
        std::cerr << "Length error: " << error.what() << std::endl;
    }
    /*================*/

    /*std::invalid_argument*/
    /*=====================*/
    try
    {
        int a = std::stoi("Hello");
    }
    catch (const std::invalid_argument& error)
    {
        std::cerr << "Invalid argument: " << error.what() << std::endl;
    }
    /*=====================*/

    /*std::bad_cast*/
    /*=============*/
    try
    {
        Class1 my_class1;
        Class1& my_class2 = my_class1;
        Class2& my_class3 = dynamic_cast<Class2&>(my_class2);
    }
    catch(const std::bad_cast& error)
    {
        std::cerr << "Bad cast: " << error.what() << std::endl;
    }
    /*=============*/

    /*std::bad_alloc*/
    /*==============*/
    //try
    //{
    //    recursion(5);
    //}
    //catch(const std::bad_alloc& error)
    //{
    //    std::cerr << "Bad alloc: " << error.what() << std::endl;
    //}
    /*==============*/

    /*==================================================================*/
    /*============================Task2=================================*/
    /*==================================================================*/

    MyException my_exception;
    my_exception.push_back(5);
    my_exception.push_back(6);
    my_exception.push_back(7);
    try
    {
        my_exception.push_index(2, 100);
    }
    catch (const MyOwnException& error)
    {
        std::cerr << "My exception: " << error.what() << std::endl;
    }

    /*==================================================================*/
    /*============================Task3=================================*/
    /*==================================================================*/

    Wrong_vec wrong;
    wrong.push_vec();
    
    return 0;
}
