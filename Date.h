//
// Created by Jakub Balicki on 14/12/2023.
//

#ifndef BANKAPP_DATE_H
#define BANKAPP_DATE_H

#include <iostream>
#include <sstream>
#include <string>
#include "fstream"

using namespace std;

extern int current_year;
extern int current_month;
extern int current_day;
void update_current_date();

class Date {
    int Year;
    int Month;
    int Day;
public:
    explicit Date(int year=1,int month=1, int day=1990);
    bool convert_from_string(const string &date);
    string convert_to_string() const;
    bool set_Year(int y);
    bool set_Month(int m);
    bool set_Day(int d);
    friend istream &operator>>(istream &os, Date &a);
    friend ostream &operator<<(ostream &os,const Date &a);
    bool save_data(ofstream &File) const;
    bool load_data(ifstream &File);
};



#endif //BANKAPP_DATE_H
