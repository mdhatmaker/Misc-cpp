//
// Created by Michael Hatmaker on 5/5/2017.
//

#ifndef TIMESERIES_SIMPLETIME_H
#define TIMESERIES_SIMPLETIME_H

#include <string>
#include <iostream>

using namespace std;

// TODO: replace all individual modifications of Time struct (add 1900 to year, etc.) with SimpleTime struct usage
struct SimpleTime {
    int year;       // four-digit year (2016, 2017, etc...)
    int month;      // 1-12
    int day;        // 1-31 (depends on month, of course)
    int hour;
    int minute;
    int second;

    SimpleTime(int year_, int month_, int day_, int hour_, int minute_, int second_) {
        year = year_;
        month = month_;
        day = day_;
        hour = hour_;
        minute = minute_;
        second = second_;
    }

    SimpleTime(const SimpleTime &t) {
        year = t.year;
        month = t.month;
        day = t.day;
        hour = t.hour;
        minute = t.minute;
        second = t.second;
    }

    SimpleTime(int year_, int month_, int day_)
            : SimpleTime(year_, month_, day_, 0, 0, 0)
    { }

    SimpleTime()
            : SimpleTime(0, 0, 0, 0, 0, 0)
    { }

    string to_csv_string();

    friend ostream& operator<<(ostream &os, const SimpleTime &t) {
        char buffer[24];
        sprintf(buffer, "%d/%d/%d %02d:%02d:%02d", t.month, t.day, t.year, t.hour, t.minute, t.second);
        std::string s(buffer);
        os << s;
        return os;
    }

    bool operator<(SimpleTime rhs);
    bool operator>(SimpleTime rhs);
    bool operator==(SimpleTime rhs);

    bool dateEquals(SimpleTime t);
    bool same_month(SimpleTime t);

    void add_month(int month_delta);
    void add_day(int day_delta);
    void add_hour(int hour_delta);

private:
    void add_day_one_month_max(int day_delta);
};


SimpleTime makeDate(const SimpleTime &t);
SimpleTime makeDate(int month, int day, int year);
SimpleTime makeDateTime(const string &date_str, const string &time_str);


struct SimpleTime_compare {
    bool operator() (const SimpleTime& lhs, const SimpleTime& rhs) const {
        if (lhs.year != rhs.year) {
            return lhs.year < rhs.year;
        }
        else if (lhs.month != rhs.month) {
            return lhs.month < rhs.month;
        }
        else if (lhs.day != rhs.day) {
            return lhs.day < rhs.day;
        }
        else if (lhs.hour != rhs.hour) {
            return lhs.hour < rhs.hour;
        }
        else if (lhs.minute != rhs.minute) {
            return lhs.minute < rhs.minute;
        }
        else {
            return lhs.second < rhs.second;
        }
    }
};

#endif //TIMESERIES_SIMPLETIME_H
