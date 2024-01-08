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
    int year;
    int month;
    int day;
public:
    Date(string date="01-01-2000");
    bool convert_from_string(string date);
    bool set_year(int y);
    bool set_month(int m);
    bool set_day(int d);
    friend istream &operator>>(istream &os, Date &a);
    friend ostream &operator<<(ostream &os,const Date &a);
    bool save_data();
    bool load_data();
};



#endif //BANKAPP_DATE_H
