//
// Created by Jakub Balicki on 08/01/2024.
//

#include "Password.h"

Password::Password(string password){
    make_Password(password);
}

bool Password::make_Password(const string &password){
    regex passwordRegex(R"((?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\W_]).{8,})");
    if(regex_match(password,passwordRegex)){
        set_Password_hash(password);
        return true;
    }
    cerr<<"Wrong or too easy password!\n";
    return false;
}

void Password::set_Password_hash(const string &password) {
    hash<string> hash_maker;
    Password_hash=hash_maker(password);
}

size_t Password::get_Password_hash(){
    return Password_hash;
}

istream &operator>>(istream &os,Password &P){
    string tmp;
    cout<<"Enter your password: ";
    getline(os,tmp);
    while(!P.make_Password(tmp))
        getline(os,tmp);
    return os;
}

bool Password::save_data(ofstream &data_file){
    if(!data_file.is_open()){
        return false;
    }
    data_file.write((char*)(&Password_hash),sizeof(Password_hash));
    return true;
}

bool Password::load_data(ifstream &data_file){
    if(!data_file.is_open()){
        return false;
    }
    data_file.read((char*)(&Password_hash),sizeof(Password_hash));
    return true;
}