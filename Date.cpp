//
// Created by Jakub Balicki on 14/12/2023.
//

#include "Date.h"

Date::Date(int year, int month, int day) : Year(year),Month(month),Day(day){}

bool Date::set_Year(int y) {
    if(!(y>=current_Year-200 && y<=current_Year)) {
        cout<<y<<" "<<current_Year<<"\n\n\n\n";
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
    if(Year==current_Year)
        if(m>current_Month){
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
    if(Year==current_Year && Month==current_Month)
        if(d>current_Day) {
            cerr<<"Wrong date!\n";
            return false;
        }
    if(current_Year-Year<18) {
        cerr<<"You are to young!\n";
        return false;
    }
    if(current_Year-Year==18){
        if(current_Month-Month<0) {
                cerr<<"You are to young!";
                return false;
        }
        if(current_Month-Month==0){
            if(current_Day-Day<0){
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

void Date::update_current_date() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    localTime_declaration;

    set_current_Day;
    set_current_Month;
    set_current_Year;
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
