//
// Created by Jakub Balicki on 08/01/2024.
//

#ifndef BANKAPP_PASSWORD_H
#define BANKAPP_PASSWORD_H

#include <string>
#include <iostream>
#include <regex>
#include <functional>
#include <fstream>

using namespace std;

class Password {
    size_t Password_hash;
public:
    Password(string password="123Tets:)");
    bool make_Password(const string &password);
    void set_Password_hash(const string &password);
    size_t get_Password_hash();
    friend istream &operator>>(istream &os,Password &P);
    bool save_data(ofstream &data_file);
    bool load_data(ifstream &data_file);
};


#endif //BANKAPP_PASSWORD_H
