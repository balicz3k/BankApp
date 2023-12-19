#ifndef BANKAPP_PERSON_H
#define BANKAPP_PERSON_H
#include <iostream>
#include <utility>
#include "Date.h"

using namespace std;

class Person {
    string Name;
    string Surname;
    Date Birth_date;
    string Address;
    string Mail;
    string Phone_number;
public:
    explicit Person(string name = "Test", string surname = "Test", string birth_date = "01-01-1990",
                    string address = "Test", string mail = "test@test.test", string phone_number="111222333");

    bool set_Name(string &a);
    bool set_Surname(string &a);
    bool set_Birth_date(string &a);
    bool set_Address(string &a);
    bool set_Mail(string &a);
    bool set_Phone_number(string &a);
    friend istream &operator>>(istream &os,Person &P);
    friend ostream &operator<<(ostream &os,const Person &P);
};

#endif //BANKAPP_PERSON_H