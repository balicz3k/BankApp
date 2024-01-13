//
// Created by Jakub Balicki on 08/01/2024.
//

#include "Database.h"

Database::Database(string File) : Source(File) {
    this->load_data();
};

void Database::add_new_record(const User &U) {
    Data.push_back(U);
    if(!save_data())
        cerr<<"Record did not add to database!\n";
}

bool Database::check_login_exist(const string &login) {
    for(auto i=0; i<Data.size(); i++){
        if(Data[i].get_Login()==login)
            return true;
    }
    return false;
}

bool Database::check_account_number_exist(const string &number) {
    for(auto i=0; Data.size() > i; i++){
        if(Data[i].get_Account_number()==number)
            return true;
    }
    return false;
}

User Database::get_user(const string &login) const{
    for(int i=0;i<Data.size();i++){
        if(Data[i].get_Login()==login)
            return Data[i];
    }
    return User();
}

void Database::remove_existing_record(const User &U) {
    for(auto i=0;i<Data.size();i++){
        if(Data[i].get_Login()==U.get_Login()){
            Data.erase(Data.begin()+i);
            i--;
        }
    }
    this->save_data();
}

Database::~Database() {
}

bool Database::load_data(){
    ifstream data_file(Source,ios::binary);
    if(!data_file.is_open()){
        cerr<<"Database connection error!\n";
        return false;
    }
    streamsize Data_size;
    data_file.read((char*)(&Data_size),sizeof(Data_size));
    User tmp;
    for(size_t i = 0; i<Data_size ; i++){
        tmp.load_data(data_file);
        Data.push_back(tmp);
    }
    data_file.close();
    return true;
}

bool Database::save_data() {
    ofstream data_file(Source,ios::binary);
    if(!data_file.is_open()){
        cerr<<"Database connection error!\n";
        return false;
    }
    auto Data_size=(streamsize)Data.size();
    data_file.write((char*)(&Data_size),sizeof(Data_size));
    for(size_t i = 0; i<Data_size ; i++){
        Data[i].save_data(data_file);
    }
    data_file.close();
    return true;
}

ostream &operator<<(ostream &os, Database &D) {
    if(D.Data.size()==0) {
        cout << "EMPTY USERS DATABASE!\n";
        return os;
    }
    for(int i=0;i<D.Data.size();i++) {
        D.Data[i].show_user_cart();
    }
    return os;
}
