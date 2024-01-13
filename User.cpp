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
    string tmp;
    for (int i = 0; i < 26; i++)
        tmp += char(rand() % 10 + '0');

    Account_number=tmp;
}
string User::get_Login() const {
    return Login;
}

istream& operator>>(istream &os, User &U){
    string tmp;
    cout<<"Enter your login: ";
    cin.ignore();
    getline(os,tmp);
    while(!U.set_Login(tmp))
        getline(os,tmp);
    os>>U.PassWord;
    os>>static_cast<Person&>(U);
    return os;
}

bool User::save_data(ofstream &File){
    if(!File.is_open()){
        cerr<<"Database error!\n";
        return false;
    }
    auto Login_size=(streamsize)Login.size();
    File.write((char*)(&Login_size), sizeof(Login_size));
    File.write(Login.data(), Login_size);

    PassWord.save_data(File);

    auto Account_number_size=(streamsize)Account_number.size();
    File.write((char*)(&Account_number_size), sizeof(Account_number_size));
    File.write(Account_number.data(), Account_number_size);

    File.write((char*)(&Balance),sizeof(Balance));

    Person::save_data(File);

    return true;
}

bool User::load_data(ifstream &File){
    if(!File.is_open()){
        cerr<<"Database connection error!\n";
        return false;
    }
    streamsize Login_size;
    File.read((char*)(&Login_size), sizeof(Login_size));
    Login.resize(Login_size);
    File.read(&Login[0], Login_size);

    PassWord.load_data(File);

    streamsize Account_number_size;
    File.read((char*)(&Account_number_size), sizeof(Account_number_size));
    Account_number.resize(Account_number_size);
    File.read(&Account_number[0], Account_number_size);

    File.read((char*)(&Balance),sizeof(Balance));

    Person::load_data(File);

    return true;
}

User::User(const string login, int balance) {
    Person();
    Login=login;
    this->generate_Account_number();
    Balance=balance;
}

string User::get_Account_number() const{
    return Account_number;
}

bool User::compare_password(const string &password) {
    return PassWord.get_Password_hash()==PassWord.get_Password_hash(password);
}

int User::get_Balance() const {
    return Balance;
}

bool User::is_enough_money(const double &amount_of_money) {
    return Balance>=amount_of_money;
}

void User::deposit() {
    double amount;
    cout<<"ENTER AMOUNT: ";
    cin>>amount;
    this->Balance+=amount;
}

bool User::withdrawal() {
    double amount;
    cout<<"ENTER AMOUNT: ";
    cin>>amount;
    if(!this->is_enough_money(amount)){
        cerr<<"NOT ENOUGH FUNDS!\n";
        return false;
    }
    Balance-=amount;
    return true;
}

void User::show_user_cart() {
    cout<<" __________________________________________________\n"
          "|,---.                                       ,---.|\n"
          "|) $ (             ACCOUNT NUMBER:           ) $ (|\n"
          "| \\ /         "<<this->Account_number<<"      \\ / |\n"
          "|  V                                           V  |\n"
          <<"\tLOGIN: "<<this->get_Login()<<'\n'
          <<"\tBALANCE: "<<this->get_Balance()<<'\n'<<
          "| / \\                                         / \\ |\n"
          "|( $ )                                       ( $ )|\n"
          "| \\ /  —-——-==========<QBANK>==========-—-——  \\ / |\n"
          "|_________________________________________________|\n";
}
