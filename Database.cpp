//
// Created by Jakub Balicki on 08/01/2024.
//

#include "Database.h"

Database::Database() {
    this->load_data();
}

void Database::add_new_record(const User &U) {
    Data.push_back(U);
    if(!save_data())
        cerr<<"Record did not add to database!\n";
    cout<<"Record added to database!\n";
}

bool Database::check_login_exist(const string &login) {
    return false;
}

bool Database::check_account_number_exist(const string &number) {
    return false;
}

void Database::remove_existing_record(const User &U) {

}

Database::~Database() {
}
bool Database::load_data() {
    ifstream data_file("/Users/balicz3k/Documents/BankApp/Database",ios::binary);
    if(!data_file.is_open()){
        cerr<<"Database connection error!\n";
        return false;
    }
    size_t size;
    data_file.read((char*)(&size),sizeof(size));
    User tmp;
    for(size_t i = 0; i<size ; i++){
        tmp.load_data(data_file);
        cout<<tmp;
        Data.push_back(tmp);
    }
    data_file.close();
    return true;
}

bool Database::save_data() {
    ofstream data_file("/Users/balicz3k/Documents/BankApp/Database",ios::binary);
    if(!data_file.is_open()){
        cerr<<"Database connection error!\n";
        return false;
    }
    size_t size=Data.size();
    data_file.write((char*)(&size),sizeof(size));
    for(size_t i = 0; i<size ; i++){
        cout<<Data[i];
        Data[i].save_data(data_file);
    }
    data_file.close();
    return true;
}
