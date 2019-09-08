//
// Created by Michael Hatmaker on 5/5/2017.
//

#include "SimpleTime.h"
#include "tools.h"
#include <vector>
#include <cassert>


bool SimpleTime::dateEquals(SimpleTime t) {
    return (year == t.year && month == t.month && day == t.day);
}

bool SimpleTime::same_month(SimpleTime t) {
    return (year == t.year && month == t.month);
}

bool SimpleTime::operator<(SimpleTime rhs) {
    if (year != rhs.year) {
        return year < rhs.year;
    }
    else if (month != rhs.month) {
        return month < rhs.month;
    }
    else if (day != rhs.day) {
        return day < rhs.day;
    }
    else if (hour != rhs.hour) {
        return hour < rhs.hour;
    }
    else if (minute != rhs.minute) {
        return minute < rhs.minute;
    }
    else {
        return second < rhs.second;
    }
}

bool SimpleTime::operator>(SimpleTime rhs) {
    if (year != rhs.year) {
        return year > rhs.year;
    }
    else if (month != rhs.month) {
        return month > rhs.month;
    }
    else if (day != rhs.day) {
        return day > rhs.day;
    }
    else if (hour != rhs.hour) {
        return hour > rhs.hour;
    }
    else if (minute != rhs.minute) {
        return minute > rhs.minute;
    }
    else {
        return second > rhs.second;
    }
}

bool SimpleTime::operator==(SimpleTime rhs) {
    return (year == rhs.year && month == rhs.month && day == rhs.day && hour == rhs.hour && minute == rhs.minute && second == rhs.second);
}

void SimpleTime::add_hour(int hour_delta) {
    assert(abs(hour_delta) < 24);
    hour += hour_delta;
    if (hour < 0) {
        hour = 24 + hour;
        add_day(-1);
    }
    else if (hour > 23) {
        hour = hour - 24;
        add_day(+1);
    }
}

void SimpleTime::add_day(int day_delta) {
    while (day_delta > 10) {
        add_day_one_month_max(10);
        day_delta -= 10;
    }
    add_day_one_month_max(day_delta);
}

void SimpleTime::add_day_one_month_max(int day_delta) {
    assert(abs(day_delta) < 28);
    day += day_delta;
    if (day < 1) {
        add_month(-1);
        day = tools::get_max_day(month, year) + day;
    }
    else if (day > tools::get_max_day(month, year)) {
        day = day - tools::get_max_day(month, year);
        add_month(+1);
    }
}

void SimpleTime::add_month(int month_delta) {
    assert(abs(month_delta) < 12);
    month += month_delta;
    if (month < 1) {
        month = 12 + month;
        --year;
    }
    else if (month > 12) {
        month = month - 12;
        ++year;
    }
}

string SimpleTime::to_csv_string() {
    char buffer[24];
    sprintf(buffer, "%d/%d/%d,%02d:%02d:%02d,", month, day, year, hour, minute, second);
    std::string s(buffer);
    return s;
}

SimpleTime makeDateTime(const string &date_str, const string &time_str) {
    vector<string> parts;
    parts = tools::split(date_str, '/');
    int month = atoi(parts[0].c_str());
    int day = atoi(parts[1].c_str());
    int year = atoi(parts[2].c_str());
    parts = tools::split(time_str, ':');
    int hour = atoi(parts[0].c_str());
    int minute = atoi(parts[1].c_str());
    int second = atoi(parts[2].c_str());
    return SimpleTime { year, month, day, hour, minute, second };
}

// Pull ONLY the date from an existing tm struct (ignoring the time)
SimpleTime makeDate(const SimpleTime &t) {
    SimpleTime ttm; // = {0};
    ttm.year = t.year;
    ttm.month = t.month;
    ttm.day = t.day;
    return ttm;
}

SimpleTime makeDate(int month, int day, int year) {
    SimpleTime ttm; // = {0};
    ttm.year = year;
    ttm.month = month;
    ttm.day = day;
    return ttm;
}

/*Time makeDateTime( int month, int day, int year, int hour, int minute, int second ) {


}*/
