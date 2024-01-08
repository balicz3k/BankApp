//
// Created by Jakub Balicki on 08/01/2024.
//

#include "User.h"

bool User::set_Login(const string &login){
    regex loginRegex("^[a-zA-Z0-9_-]{3,16}$");
    if(regex_match(login,loginRegex)){
        Login=login;
        return true;
    }
    cerr<<"Wrong login!\n";
    return false;
}

void User::generate_Account_number(){
    string tmp="";
    for (int i = 0; i < 26; i++) {
        tmp += char(rand() % 10 + '0');
    }
    Account_number=tmp;
}
string User::get_Login(){
    return Login;
}

istream& operator>>(istream &os, User &U){
    string tmp;
    cout<<"Enter your login: ";
    getline(os,tmp);
    while(!U.set_Login(tmp))
        getline(os,tmp);
    os>>U.PassWord;
    os>>static_cast<Person&>(U);
    return os;
}

bool User::save_data(ofstream &data_file){
    if(!data_file.is_open()){
        cerr<<"Database error!\n";
        return false;
    }
    data_file.write((char*)(this), sizeof(User));
    return true;
}

bool User::load_data(ifstream &data_file){
    if(!data_file.is_open()){
        cerr<<"Database connection error!\n";
        return false;
    }
    data_file.read((char*)(this), sizeof(User));
    return true;
}

User::User(string login, int balance) {
    Person();
    Login=login;
    this->generate_Account_number();
    Balance=balance;
}

string User::get_Account_number() {
    return Account_number;
}
