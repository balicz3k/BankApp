//
// Created by Jakub Balicki on 11/01/2024.
//

#ifndef BANKAPP_INTERFACE_H
#define BANKAPP_INTERFACE_H
#include <iostream>
#include "InvalidChoiceException.h"

#ifdef _WIN32
#include <windows.h>
#define CLEAR system("cls")
#define WAIT system("pause")
#elif __linux__ || __APPLE__
#include <cstdlib>
#define CLEAR system("clear")
#define WAIT cout<<"PRESS ENTER TO CONTINUE!\n"; cin.get()
#endif


using namespace std;

class Interface {
protected:
    int Options;
    int Choice;
    bool Exit;
public:
    Interface(const int options, const int choice);

    virtual void show_menu() = 0;
    virtual void execute() = 0;
    void read_input();
    template <typename Type>
    bool correct_input(const Type &input);
    bool get_Exit();
    void clear_screen();
    void wait_for_click_button();

    void end_communicat();
};

template <typename Type>
bool Interface::correct_input(const Type &input) {
    return 1<=input && input<=Options;
}


#endif //BANKAPP_INTERFACE_H
