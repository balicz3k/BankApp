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
    if(Birth_date.convert_from_string(a))
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

bool Person::set_Pesel(string &a) {
    regex peselRegex("^[0-9]{11}$");
    if(a.empty()) {
        cerr<<"Wrong pesel!\n";
        return false;
    }
    if(regex_match(a, peselRegex)) {
        Pesel = a;
        return true;
    }
    cerr<<"Wrong pesel!\n";
    return false;
}

bool Person::set_Mail(string &a) {
    if(a.empty()) {
        cerr<<"Wrong e-mail!\n";
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

    Person::Person(string name, string surname, string birth_date, string pesel, string address, string mail, string phone_number) {
    set_Name(name);
    set_Surname(surname);
    set_Birth_date(birth_date);
    set_Pesel(pesel);
    set_Address(address);
    set_Mail(mail);
    set_Phone_number(phone_number);
}

ostream &operator<<(ostream &os, const Person &P) {
    os<<"Name: "<<P.Name<<'\n';
    os<<"Surname: "<<P.Surname<<'\n';
    os<<P.Birth_date<<'\n';
    os<<"Pesel: "<<P.Pesel<<'\n';
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

    cout<<"Enter your Pesel: ";
    getline(os,tmp);
    while(!P.set_Pesel(tmp))
        getline(os,tmp);

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

bool Person::save_data(ofstream &data_file){
    if(!data_file.is_open()){
        return false;
    }

    size_t size=Name.size();
    data_file.write((char*)(&size),sizeof(size));
    data_file.write(Name.data(),Name.size());

    size=Surname.size();
    data_file.write((char*)(&size),sizeof(size));
    data_file.write(Surname.data(),Surname.size());

    Birth_date.save_data(data_file);

    size=Pesel.size();
    data_file.write((char*)(&size),sizeof(size));
    data_file.write(Pesel.data(),Pesel.size());

    size=Address.size();
    data_file.write((char*)(&size),sizeof(size));
    data_file.write(Address.data(),Address.size());

    size=Mail.size();
    data_file.write((char*)(&size),sizeof(size));
    data_file.write(Mail.data(),Mail.size());

    size=Phone_number.size();
    data_file.write((char*)(&size),sizeof(size));
    data_file.write(Phone_number.data(),Phone_number.size());

    return true;
}
bool Person::load_data(ifstream &data_file) {
    if(!data_file.is_open()){
        return false;
    }

    size_t nameSize;
    data_file.read((char*)(&nameSize), sizeof(nameSize));
    Name.resize(nameSize);
    data_file.read(&Name[0], nameSize);

    size_t surnameSize;
    data_file.read((char*)(&surnameSize), sizeof(surnameSize));
    Surname.resize(surnameSize);
    data_file.read(&Surname[0], surnameSize);

    Birth_date.load_data(data_file);

    size_t peselSize;
    data_file.read((char*)(&peselSize), sizeof(peselSize));
    Pesel.resize(peselSize);
    data_file.read(&Pesel[0], peselSize);

    size_t addressSize;
    data_file.read((char*)(&addressSize), sizeof(addressSize));
    Address.resize(addressSize);
    data_file.read(&Address[0], addressSize);

    size_t mailSize;
    data_file.read((char*)(&mailSize), sizeof(mailSize));
    Mail.resize(mailSize);
    data_file.read(&Mail[0], mailSize);

    size_t phoneNumberSize;
    data_file.read((char*)(&phoneNumberSize), sizeof(phoneNumberSize));
    Phone_number.resize(phoneNumberSize);
    data_file.read(&Phone_number[0], phoneNumberSize);

    return true;
}
