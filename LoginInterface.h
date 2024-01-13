//
// Created by Jakub Balicki on 11/01/2024.
//

#ifndef BANKAPP_LOGININTERFACE_H
#define BANKAPP_LOGININTERFACE_H
#include "Interface.h"
#include "User.h"
#include "Database.h"

class LoginInterface :public Interface{
    User Logged_user;
public:
    LoginInterface(const int options=4,const int choice=-1);
    void start_animation();
    void show_info();
    void show_menu();
    void execute();
    bool login();
    void set_Exit_true();
    ~LoginInterface();
};


#endif //BANKAPP_LOGININTERFACE_H
