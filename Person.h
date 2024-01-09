#ifndef BANKAPP_PERSON_H
#define BANKAPP_PERSON_H
#include <iostream>
#include <utility>
#include "Date.h"
#include "fstream"

using namespace std;

class Person {
    string Name;
    string Surname;
    Date Birth_date;
    string Pesel;
    string Address;
    string Mail;
    string Phone_number;
public:
    explicit Person(string name = "Test",
                    string surname = "Test",
                    string birth_date = "01-01-1990",
                    string pesel = "00000000000",
                    string address = "Test",
                    string mail = "test@test.test",
                    string phone_number="111222333");

    bool set_Pesel(string &a);
    bool set_Name(string &a);
    bool set_Surname(string &a);
    bool set_Birth_date(string &a);
    bool set_Address(string &a);
    bool set_Mail(string &a);
    bool set_Phone_number(string &a);
    friend istream &operator>>(istream &os,Person &P);
    friend ostream &operator<<(ostream &os,const Person &P);
    bool save_data(ofstream &data_file);
    bool load_data(ifstream &data_file);
};

#endif //BANKAPP_PERSON_H
