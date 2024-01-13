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
    double Balance;
public:
    User(const string login="test",int balance=0);
    bool set_Login(const string &login);
    void generate_Account_number();
    string get_Login() const;
    string get_Account_number() const;
    int get_Balance() const;
    void show_user_cart();
    friend istream& operator>>(istream &os, User &U);
    bool is_enough_money(const double &amount_of_money);
    void deposit();
    bool withdrawal();
    bool compare_password(const string &password);
    bool save_data(ofstream &File) override;
    bool load_data(ifstream &File) override;
};


#endif //BANKAPP_USER_H
