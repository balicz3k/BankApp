//
// Created by Jakub Balicki on 08/01/2024.
//

#ifndef BANKAPP_USER_H
#define BANKAPP_USER_H
#include "Person.h"
#include "Password.h"
#include <fstream>

class User : public Person{
    string Login;
    Password PassWord;
    string Account_number;
    int Balance;
public:
    User(string login="test",int balance=0);
    bool set_Login(const string &login);
    void generate_Account_number();
    string get_Login();
    string get_Account_number();
    friend istream& operator>>(istream &os, User &U);
    bool save_data(ofstream &data_file);
    bool load_data(ifstream &data_file);
};


#endif //BANKAPP_USER_H
