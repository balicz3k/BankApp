//
// Created by Jakub Balicki on 11/01/2024.
//

#include "Interface.h"

bool Interface::get_Exit(){
    return Exit;
}

Interface::Interface(const int options, const int choice)
: Options(options), Choice(choice), Exit(false) {}

void Interface::read_input() {
    int input;
    bool error_communicat=false;
    try {
        cout << "ENTER YOUR CHOICE [ 1 - "
             << Options << " ]: ";
        cin >> input;
        if(cin.fail()){
            throw InvalidChoiceException();
        }
        if(!correct_input((input)))
            throw OutOfRangeException();
    }
    catch (const exception& e){
        if(!error_communicat) {
            cerr << e.what() << '\n';
            error_communicat = true;
        }
        cin.clear();
        cin.ignore();
        this->read_input();
    }
    Choice=input;
}

void Interface::end_communicat() {
    cout<<"THANKS FOR BEING WITH US!\n";
}

void Interface::clear_screen() {
    CLEAR;
}

void Interface::wait_for_click_button() {
    WAIT;
}


