//
// Created by Jakub Balicki on 11/01/2024.
//

#ifndef BANKAPP_ADMININTERFACE_H
#define BANKAPP_ADMININTERFACE_H

#include "Interface.h"
#include "User.h"
#include "Database.h"
#include <string>

class AdminInterface: public Interface{
public:
    AdminInterface(const int options=4,const int choice=-1);
    void start_animation();
    void show_menu();
    void execute();
};


#endif //BANKAPP_ADMININTERFACE_H
