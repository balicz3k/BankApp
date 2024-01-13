//
// Created by Jakub Balicki on 08/01/2024.
//

#include "Password.h"


bool Password::make_Password(const string &password){
    std::regex passwordRegex(R"((?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[!@#$%^&*()_\-+=<>?/{}[\]|\W_]).{8,})");
    if(regex_match(password,passwordRegex)){
        Password_hash=get_Password_hash(password);
        return true;
    }
    cerr<<"Wrong or too easy password!\n";
    return false;
}

size_t Password::get_Password_hash(const string &password) {
    hash<string> hash_maker;
    return hash_maker(password);
}

size_t Password::get_Password_hash() const{
    return Password_hash;
}

istream &operator>>(istream &os,Password &P){
    string tmp;
    cout<<"Enter your password: ";
    getline(os,tmp);
    while(!P.make_Password(tmp)) {
        getline(os, tmp);
    }
    return os;
}

bool Password::save_data(ofstream &File){
    if(!File.is_open()){
        return false;
    }
    File.write((char*)(&Password_hash), sizeof(Password_hash));
    return true;
}

bool Password::load_data(ifstream &File){
    if(!File.is_open()){
        return false;
    }
    File.read((char*)(&Password_hash), sizeof(Password_hash));
    return true;
}