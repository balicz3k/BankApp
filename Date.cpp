//
// Created by Jakub Balicki on 14/12/2023.
//

#include "Date.h"

int current_year;
int current_month;
int current_day;

Date::Date(string str_date) {
    convert_from_string(str_date);
}

bool Date::set_year(int y) {
    if(!(y>=current_year-200 && y<=current_year)) {
        cout<<y<<" "<<current_year<<"\n\n\n\n";
        cerr<<"Wrong year!\n";
        return false;
    }
    year=y;
    return true;
}

bool Date::set_month(int m) {
    if(!(m>=1&&m<=12)) {
        cerr<<"Wrong month!\n";
        return false;
    }
    if(year==current_year)
        if(m>current_month){
            cerr<<"Wrong date!\n";
            return false;
        }
    month=m;
    return true;
}

bool Date::set_day(int d) {
    if(!(d>=1 && d<=31)){
        cerr<<"Wrong day!\n";
        return false;
    }
    if(year==current_year && month==current_month)
        if(d>current_day) {
            cerr<<"Wrong date!\n";
            return false;
        }
    if(current_year-year<18) {
        cerr<<"You are to young!\n";
        return false;
    }
    if(current_year-year==18){
        if(current_month-month<0) {
                cerr<<"You are to young!";
                return false;
        }
        if(current_month-month==0){
            if(current_day-day<0){
                cerr<<"You are to young!";
                return false;
            }
        }
    }
    day=d;
    return true;
}

bool Date::convert_from_string(string date){
    update_current_date();
    istringstream stream(date);
    int d,m,y;
    char sign;
    stream >> d >> sign >> m >> sign >> y;
    if (stream.fail() || sign != '-') {
        cerr << "Incorrect date format!\n";
        return false;
    }
    if(!set_year(y)) return false;
    if(!set_month(m)) return false;
    if(!set_day(d)) return false;
    return true;
}

istream &operator>>(istream &os, Date &a) {
    cout<<"Enter your birth date [dd-mm-yyyy]: ";
    string str;
    getline(os,str);
    while(!a.convert_from_string(str)){
        getline(os,str);
    }
    return os;
}

ostream &operator<<(ostream &os,const Date &a) {
    os<<"Date of birth: "<<(a.day<10 ? "0" : "")<<a.day <<'-'<<(a.month<10 ? "0" : "")<<a.month<<'-'<<a.year;
    return os;
}

void update_current_date() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&currentTime);
    current_year=1900+localTime->tm_year;
    current_month=localTime->tm_mon+1;
    current_day=localTime->tm_mday;
}

bool Date::save_data(){
    ofstream data_file("/Users/balicz3k/Documents/BankApp/Database",ios::binary);
    if(!data_file.is_open()){
        return false;
    }
    data_file.write((char*)(this),sizeof(Date));
    data_file.close();
    return true;
}

bool Date::load_data(){
    ifstream data_file("/Users/balicz3k/Documents/BankApp/Database",ios::binary);
    if(!data_file.is_open()){
        return false;
    }
    data_file.read((char*)(this),sizeof(Date));
    return true;
}
