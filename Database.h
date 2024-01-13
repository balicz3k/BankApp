//
// Created by Jakub Balicki on 08/01/2024.
//

#ifndef BANKAPP_DATABASE_H
#define BANKAPP_DATABASE_H
#include <vector>
#include <set>
#include "User.h"
#include <fstream>

class Database {
    string Source;
    vector<User>Data;
public:
    Database(string file = "/Users/balicz3k/Documents/BankApp/Users");
    bool load_data();
    bool save_data();
    void add_new_record(const User &U);
    bool check_login_exist(const string &login);
    bool check_account_number_exist(const string &number);
    User get_user(const string &login) const;
    void remove_existing_record(const User &U);
    ~Database();
    friend ostream& operator<<(ostream &os, Database &D);
};


#endif //BANKAPP_DATABASE_H
