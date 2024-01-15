//
// Created by Jakub Balicki on 14/12/2023.
//

#ifndef BANKAPP_DATE_H
#define BANKAPP_DATE_H

#include <iostream>
#include <string>
#include "fstream"

#ifdef _WIN32
#include <chrono>
#include <ctime>
#define localTime_declaration tm localTime; gmtime_s(&localTime, &currentTime)
#define set_current_Year current_Year = 1900 + localTime.tm_year;
#define set_current_Month current_Month = localTime.tm_mon + 1;
#define set_current_Day current_Day = localTime.tm_mday;
#elif __linux__ || __APPLE__
#include <sstream>
#define localTime_declaration tm* localTime = localtime(&currentTime)
#define set_current_Year current_Year=1900+localTime->tm_year
#define set_current_Month current_Month=localTime->tm_mon+1
#define set_current_Day current_Day=localTime->tm_mday
#endif

using namespace std;

class Date {
    int Year;
    int Month;
    int Day;
    int current_Year;
    int current_Month;
    int current_Day;

public:
    explicit Date(int year=1,int month=1, int day=1990);
    bool convert_from_string(const string &date);
    string convert_to_string() const;
    bool set_Year(int y);
    bool set_Month(int m);
    bool set_Day(int d);
    friend istream &operator>>(istream &os, Date &a);
    friend ostream &operator<<(ostream &os,const Date &a);
    void update_current_date();
    bool save_data(ofstream &File) const;
    bool load_data(ifstream &File);
};



#endif //BANKAPP_DATE_H
