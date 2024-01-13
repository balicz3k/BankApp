//
// Created by Jakub Balicki on 11/01/2024.
//

#include "LoginInterface.h"

void LoginInterface::show_info() {
    Logged_user.show_user_cart();
}

void LoginInterface::show_menu() {
    cout<<"CHOSE OPERATION:\n"
          "1 - DEPOSIT\n"
          "2 - WITHDRAWAL\n"
          "3 - YOUR DATA\n"
          "4 - LOGOUT\n";
}


void LoginInterface::execute() {
    Database D;
    switch(Choice){
        case 1:
            Logged_user.deposit();
            D.remove_existing_record(Logged_user.get_Login());
            D.add_new_record(Logged_user);
            break;
        case 2:
            Logged_user.withdrawal();
            D.remove_existing_record(Logged_user);
            D.add_new_record(Logged_user);
            break;
        case 3:
            this->clear_screen();
            cout<<Logged_user<<'\n';
            cin.ignore();
            this->wait_for_click_button();
            break;
        case 4:
            Interface::Exit=true;
            break;
        default:
            Interface::Exit=true;
    }

}

bool LoginInterface::login() {
    string login,password;

    cout<<"ENTER LOGIN: ";
    cin.ignore();
    getline(cin,login);

    cout<<"ENTER PASSWORD: ";
    getline(cin,password);
    Database D;
    if(!D.check_login_exist(login)) {
        cerr<<"INVALID LOGIN!\n";
        return false;
    }

    Logged_user=D.get_user(login);
    if(!Logged_user.compare_password(password)) {
        cerr<<"INVALID PASSWORD!\n";
        return false;
    }

    return true;
}

LoginInterface::LoginInterface(const int options, const int choice) : Interface(options,choice) {}

void LoginInterface::set_Exit_true() {
    Interface::Exit=true;
}

LoginInterface::~LoginInterface() {

}
