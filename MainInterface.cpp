//
// Created by Jakub Balicki on 11/01/2024.
//

#include "MainInterface.h"

MainInterface::MainInterface(const int options, const int choice)
: Interface(options,choice) {}

void MainInterface::start_animation(){
    cout<<" ________  ________  ________  ________   ___  __       \n"
          "|\\   __  \\|\\   __  \\|\\   __  \\|\\   ___  \\|\\  \\|\\  \\     \n"
          "\\ \\  \\|\\  \\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\/  /|_   \n"
          " \\ \\  \\\\\\  \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\   ___  \\  \n"
          "  \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\ \\  \\ \n"
          "   \\ \\_____  \\ \\_______\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\__\\\\ \\__\\\n"
          "    \\|___| \\__\\|_______|\\|__|\\|__|\\|__| \\|__|\\|__| \\|__|\n"
          "          \\|__|   \n\n";
}

void MainInterface::show_menu() {
    cout<<"CHOSE OPERATION:\n"
          "1 - SIGN UP\n"
          "2 - LOG IN\n"
          "3 - ADMIN VIEW\n"
          "4 - EXIT\n";
}

void MainInterface::execute() {
    string PIN;
    Password P;
    bool access=true;
    AdminInterface A;
    LoginInterface L;
    Database D;
    User U;
    switch(Choice){
        case 1:
            cin>>U;
            D.add_new_record(U);
            break;
        case 2:
            if(!L.login()){
                L.set_Exit_true();
            }
            while(!L.get_Exit()){
                L.show_info();
                L.show_menu();
                L.read_input();
                L.execute();
            }
            D.load_data();
            break;
        case 3:
            cout<<"ENTER PIN: ";
            cin.ignore();
            getline(cin,PIN);
            if(P.get_Password_hash(PIN)!=2968498615519751340) {
                access = false;
                cerr<<"ACCESS DENIED!\n";
            }
            while(!A.get_Exit()&&access) {
                A.start_animation();
                A.show_menu();
                A.read_input();
                A.execute();
            }
            break;
        case 4:
            Interface::Exit=true;
            this->end_communicat();
            break;
    }
}
