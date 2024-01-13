//
// Created by Jakub Balicki on 11/01/2024.
//

#include "AdminInterface.h"

AdminInterface::AdminInterface(const int options, const int choice)
        : Interface(options,choice) {}

void AdminInterface::start_animation(){
    cout<<"    .-.\n"
          "  .-. |\n"
          ".-. | |\n"
          "| | | | ___\n"
          "| | | |/ _ \\     ___\n"
          "|       /o\\_'||.' o `.\n"
          "|       \\=/ /|| `---'\n"
          " \\      ___//  \\\n"
          "  \\____/   (`__')\n"
          "       ///////\\\\\\\\\\\\\\\n"
          "        `--.____.--'  . . . ADMIN VIEW\n\n";
}

void AdminInterface::show_menu() {
    cout<<"CHOSE OPERATION:\n"
          "1 - ADD USER\n"
          "2 - REMOVE USER\n"
          "3 - SHOW ALL USERS\n"
          "4 - BACK TO MAIN MENU\n\n";
}

void AdminInterface::execute() {
    Database D;
    User U;
    string login;
    switch(Choice){
        case 1:
            this->clear_screen();
            cin>>U;
            D.add_new_record(U);
            break;
        case 2:
            cout<<"ENTER USERS TO REMOVE LOGIN: ";
            cin.ignore();
            getline(cin,login);
            U=D.get_user(login);
            D.remove_existing_record(U);
            break;
        case 3:
            cout<<D<<'\n';
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
