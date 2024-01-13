//
// Created by Jakub Balicki on 12/01/2024.
//

#ifndef BANKAPP_INVALIDCHOICEEXCEPTION_H
#define BANKAPP_INVALIDCHOICEEXCEPTION_H
#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidChoiceException:public exception{
public:
    const char* what() const noexcept override {
        return "INCORRECT INPUT!";
    }
};

class OutOfRangeException : public std::out_of_range {
public:
    OutOfRangeException() : std::out_of_range("NUMBER OUT OF RANGE") {}
};

#endif //BANKAPP_INVALIDCHOICEEXCEPTION_H
