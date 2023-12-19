//
// Created by Jakub Balicki on 14/12/2023.
//

#include "Person.h"
#include <cctype>
#include <regex>




bool Person::set_Name(string &a) {
    if(a.empty()){
        cerr<<"Wrong name!\n";
        return false;
    }
    regex nameRegex(R"([A-Za-zęóąśłżźćńĘÓĄŚŁŻŹĆŃ]+(?: [A-Za-zęóąśłżźćńĘÓĄŚŁŻŹĆŃ]+)?)");
    if (!regex_match(a, nameRegex)) {
        cerr << "Wrong name!\n";
        return false;
    }
    a[0]=toupper(a[0]);
    for(int i=1;i<a.size();i++) {
        if(a[i] == ' ' || a[i] == '-'){
            ++i;
            a[i]=toupper(a[i]);
            continue;
        }
        a[i]=tolower(a[i]);
    }
    Name=a;
    return true;
}

bool Person::set_Surname(string &a) {
    if(a.empty()){
        cerr<<"Wrong surname!\n";
        return false;
    }
    regex surnameRegex(R"([A-Za-zęóąśłżźćńĘÓĄŚŁŻŹĆŃ]+(?:[-\s][A-Za-zęóąśłżźćńĘÓĄŚŁŻŹĆŃ]+)?)");
    if (!regex_match(a, surnameRegex)) {
        cerr << "Wrong surname!\n";
        return false;
    }
    a[0]=toupper(a[0]);
    for(int i=1;i<a.size();i++) {
        if(a[i] == ' ' || a[i] == '-'){
            ++i;
            a[i]=toupper(a[i]);
            continue;
        }
        a[i]=tolower(a[i]);
    }
    Surname=a;
    return true;
}

bool Person::set_Birth_date(string &a) {
    if(Birth_date.FromString(a))
        return true;
    return false;
}

bool Person::set_Address(string &a) {
    if(a.empty()) {
        cerr<<"Wrong address!\n";
        return false;
    }
    Address=a;
    return true;
}

bool Person::set_Mail(string &a) {
    if(a.empty()) {
        cerr<<"Wrong address!\n";
        return false;
    }
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    if (!regex_match(a, emailRegex)) {
        cerr << "Wrong e-mail!\n";
        return false;
    }
    Mail=a;
    return true;
}

bool Person::set_Phone_number(string &a) {
    if(a.size()!=9){
        cerr<<"Wrong number!\n";
        return false;
    }
    for(int i=0;i<9;i++){
        if(!(a[i]>='0' && a[i]<='9')){
            cerr<<"Wrong number!\n";
            return false;
        }
    }
    Phone_number=a;
    return true;
}

    Person::Person(string name, string surname, string birth_date, string address, string mail, string phone_number) {
    set_Name(name);
    set_Surname(surname);
    set_Birth_date(birth_date);
    set_Address(address);
    set_Mail(mail);
    set_Phone_number(phone_number);
}

ostream &operator<<(ostream &os, const Person &P) {
    os<<"Name: "<<P.Name<<'\n';
    os<<"Surname: "<<P.Surname<<'\n';
    os<<P.Birth_date<<'\n';
    os<<"Address: "<<P.Address<<'\n';
    os<<"e-Mail: "<<P.Mail<<'\n';
    os<<"Phone number: "<<P.Phone_number;
    return os;
}

istream &operator>>(istream &os, Person &P) {
    string tmp;

    cout<<"Enter your first name: ";
    getline(os,tmp);
    while(!P.set_Name(tmp))
        getline(os,tmp);

    cout<<"Enter your last name: ";
    getline(os,tmp);
    while(!P.set_Surname(tmp))
        getline(os,tmp);

    cin>>P.Birth_date;

    cout<<"Enter your address: ";
    getline(os,tmp);
    while(!P.set_Address(tmp))
        getline(os,tmp);

    cout<<"Enter your e-Mail: ";
    getline(os,tmp);
    while(!P.set_Mail(tmp))
        getline(os,tmp);

    cout<<"Enter your phone number: ";
    getline(os,tmp);
    while(!P.set_Phone_number(tmp))
        getline(os,tmp);

    return os;
}
