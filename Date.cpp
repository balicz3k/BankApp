//
// Created by Jakub Balicki on 14/12/2023.
//

#include "Date.h"

int current_year;
int current_month;
int current_day;

Date::Date(int year, int month, int day) : Year(year),Month(month),Day(day){}

bool Date::set_Year(int y) {
    if(!(y>=current_year-200 && y<=current_year)) {
        cout<<y<<" "<<current_year<<"\n\n\n\n";
        cerr<<"Wrong year!\n";
        return false;
    }
    Year=y;
    return true;
}

bool Date::set_Month(int m) {
    if(!(m>=1&&m<=12)) {
        cerr<<"Wrong month!\n";
        return false;
    }
    if(Year==current_year)
        if(m>current_month){
            cerr<<"Wrong date!\n";
            return false;
        }
    Month=m;
    return true;
}

bool Date::set_Day(int d) {
    if(!(d>=1 && d<=31)){
        cerr<<"Wrong day!\n";
        return false;
    }
    if(Year==current_year && Month==current_month)
        if(d>current_day) {
            cerr<<"Wrong date!\n";
            return false;
        }
    if(current_year-Year<18) {
        cerr<<"You are to young!\n";
        return false;
    }
    if(current_year-Year==18){
        if(current_month-Month<0) {
                cerr<<"You are to young!";
                return false;
        }
        if(current_month-Month==0){
            if(current_day-Day<0){
                cerr<<"You are to young!";
                return false;
            }
        }
    }
    Day=d;
    return true;
}

bool Date::convert_from_string(const string &date){
    update_current_date();
    istringstream stream(date);
    int d,m,y;
    char sign;
    stream >> d >> sign >> m >> sign >> y;
    if (stream.fail() || sign != '-') {
        cerr << "Incorrect date format!\n";
        return false;
    }
    if(!set_Year(y)) return false;
    if(!set_Month(m)) return false;
    if(!set_Day(d)) return false;
    return true;
}

string Date::convert_to_string() const{
    string tmp;
    tmp+=(Day<10 ? "0" : "");
    tmp+= to_string(Day);
    tmp+='-';
    tmp+=(Month<10 ? "0" : "");
    tmp+= to_string(Month);
    tmp+='-';
    tmp+=to_string(Year);
    return tmp;
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
    os<<"Date of birth: "<<(a.Day<10 ? "0" : "")<<a.Day <<'-'<<(a.Month<10 ? "0" : "")<<a.Month<<'-'<<a.Year;
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

bool Date::save_data(ofstream &File) const{
    if(!File.is_open()){
        return false;
    }
    string tmp=this->convert_to_string();
    auto Data_size=(streamsize)tmp.size();
    File.write((char*)(&Data_size), sizeof(Data_size));
    File.write(tmp.data(), Data_size);

    return true;
}

bool Date::load_data(ifstream &File){
    if(!File.is_open()){
        return false;
    }
    streamsize Data_size;
    string tmp;
    File.read((char*)(&Data_size),sizeof(Data_size));
    tmp.resize(Data_size);
    File.read((char*)&tmp[0],Data_size);

    this->convert_from_string(tmp);

    return true;
}
