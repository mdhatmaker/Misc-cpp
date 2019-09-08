//
// Created by Michael Hatmaker on 4/29/17.
//

#include "tools.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

namespace tools {
    // Split a string by a specified delimeter
    // put results in a pre-constructed vector
    template<typename Out>
    void split(const string &s, char delim, Out result) {
        stringstream ss;
        ss.str(s);
        string item;
        while (getline(ss, item, delim)) {
            *(result++) = item;
        }
    }

    // Split a string by a specified delimeter
    // put results in a new vector
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, back_inserter(elems));
        return elems;
    }


    int get_max_day(int month, int year) {
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;
        else if(month == 4 || month == 6 || month == 9 || month == 11)
            return 30;
        else {
            if(year % 4 == 0) {
                if(year % 100 == 0) {
                    if(year % 400 == 0)
                        return 29;
                    return 28;
                }
                return 29;
            }
            return 28;
        }
    }

    // Use zellers congruence to calculate the day of the week
    // Sun=1, Mon=2, ..., Sat=7
    int get_day_of_week(int month, int day, int year) {
        int q = day;
        int m = month;
        int k = year % 100;
        int j = year / 100;
        int h = (q + 26 *(m+1)/10 + k + k/4 + j/4 + 5 *j) % 7;
        return h;
    }

    bool is_weekend(int month, int day, int year) {
        int dow = get_day_of_week(month, day, year);
        return (dow == 1 || dow == 7);
    }

    bool is_weekday(int month, int day, int year) {
        return !is_weekend(month, day, year);
    }

    bool is_leap_year(int y) {
        int tf = (y % 4) ? 0 : ((y % 100) ? 1 : !(y % 400));
        return tf != 0;                                         // might be better to cast from int to bool?
    }

    string tail(string const& source, size_t const length) {
        if (length >= source.size()) { return source; }
        return source.substr(source.size() - length);
    }


    /*// Basic method to iterate through a series of dates
    Time startDate=makeDate(1, 1, 2017);
    Time endDate=makeDate(4, 29, 2017);
    time_t end=mktime(&endDate);
    for(Time date=startDate;end>=mktime(&date);++date.tm_mday) {
    }*/


} // namespace tools