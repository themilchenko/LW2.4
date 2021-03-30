#include <iostream>
#include <string>
#include <exception>

#ifndef LW2_4_MYOWNEXCEPTION_H
#define LW2_4_MYOWNEXCEPTION_H


class MyOwnException : public std::exception
{
private:
    std::string error;

public:
    MyOwnException(const std::string& err) : error(err) { };

    const char* what() const noexcept { return error.c_str(); }

};


#endif //LW2_4_MYOWNEXCEPTION_H