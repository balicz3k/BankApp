//
// Created by Jakub Balicki on 11/01/2024.
//

#ifndef BANKAPP_MAININTERFACE_H
#define BANKAPP_MAININTERFACE_H
#include "Interface.h"
#include "User.h"
#include "Database.h"
#include "AdminInterface.h"
#include "LoginInterface.h"

class MainInterface:public Interface {
public:
    MainInterface(const int options=4,const int choice=-1);
    void start_animation();
    void show_menu();
    void execute();
};


#endif //BANKAPP_MAININTERFACE_H
