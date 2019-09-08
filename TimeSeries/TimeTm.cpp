//
// Created by Michael Hatmaker on 5/5/2017.
//

#include "TimeTm.h"
#include "tools.h"

namespace Time {

    string to_string(const TimeTm &t) {
        char buffer[24];
        strftime(buffer, sizeof(buffer), "%d%b%Y %H:%M:%S", &t);
        std::string s(buffer);
        return s;
    }

    string to_csv_string(const TimeTm &t) {
        char buffer[24];
        strftime(buffer, sizeof(buffer), "%m/%d/%Y,%H:%M:%S,", &t);
        std::string s(buffer);
        return s;
    }

    time_t to_rawtime(const TimeTm &t) {
        TimeTm ttm = {0};
        ttm.tm_mon = t.tm_mon;
        ttm.tm_mday = t.tm_mday;
        ttm.tm_year = t.tm_year;
        ttm.tm_hour = t.tm_hour;
        ttm.tm_min = t.tm_min;
        ttm.tm_sec = t.tm_sec;
        return mktime(&ttm);
    }

    TimeTm add_month(const TimeTm &t, int mon_delta) {
        TimeTm ttm = {0};
        int m = t.tm_mon + mon_delta;
        if (m < 0) {
            ttm.tm_mon = 12 + (m % 12);
            ttm.tm_year = t.tm_year + (m / 12) - 1;
            ttm.tm_mday = max(t.tm_mday, tools::get_max_day(ttm.tm_mon, ttm.tm_year));
        }
        else {
            ttm.tm_mon = m % 12;
            ttm.tm_year = t.tm_year + (m / 12);
            ttm.tm_mday = max(t.tm_mday, tools::get_max_day(ttm.tm_mon, ttm.tm_year));
        }
        return ttm;
    }

    TimeTm add_day(const TimeTm &t, int day_delta) {
        time_t raw = to_rawtime(t);
        int seconds_in_day = (60 * 60 * 24);
        int seconds_to_add = day_delta < 0 ? -seconds_in_day : +seconds_in_day;
        for (int i = 0; i < abs(day_delta); ++i) {
            raw += seconds_to_add;
        }
        TimeTm *ttm;
        ttm = localtime(&raw);
        return *ttm;
    }

    TimeTm add_hour(const TimeTm &t, int hour_delta) {
        time_t raw = to_rawtime(t);
        int seconds_in_hour = (60 * 60);
        raw += seconds_in_hour * hour_delta;
        TimeTm *ttm;
        ttm = localtime(&raw);
        return *ttm;
    }

    int days_between(TimeTm *tsa, TimeTm *tsb) {
        time_t a = mktime(tsa);
        time_t b = mktime(tsb);
        return (b - a) / (60 * 60 * 24);
    }

// Is this an alternative to the calculation for get_max_day function?
    int days_of_month(int m, int y) {
        TimeTm tsa = {0};
        TimeTm tsb = {0};

        tsa.tm_mon = m - 1;                     // month in Time struct is zero-based
        tsa.tm_mday = 1;
        tsa.tm_year = y - 1900;                 // year in Time struct is years since 1900

        if (m == 12) {                          // we have to handle Dec differently
            tsb.tm_mon = 0;                     // tsb is Jan
            tsb.tm_mday = 1;
            tsb.tm_year = y + 1 - 1900;         // of the following year
        } else {
            tsb.tm_mon = m;                     // tsb is the following month
            tsb.tm_mday = 1;
            tsb.tm_year = y - 1900;             // of the same year
        }

        return days_between(&tsa, &tsb);
    }

// Return number of days in a specified (4-digit) year
    int days_of_year(int y) {
        TimeTm tsa = {0};
        TimeTm tsb = {0};

        tsa.tm_mday = 1;
        tsa.tm_year = y - 1900;

        tsb.tm_mday = 1;
        tsb.tm_year = y + 1 - 1900;

        return days_between(&tsa, &tsb);
    }

    bool is_weekend(TimeTm t) {
        time_t raw = mktime(&t);
        TimeTm *ttm = localtime(&raw);
        return ttm->tm_wday == 0 || ttm->tm_wday == 6;
    }

    bool is_weekday(TimeTm t) {
        return !is_weekend(t);
    }

    TimeTm makeDate(int month, int day, int year) {
        TimeTm ttm = {0};
        ttm.tm_mon = month - 1;
        ttm.tm_mday = day;
        ttm.tm_year = year - 1900;
        //time_t raw = mktime(&ttm);
        //Time *tm = localtime(&raw);
        //return *tm;
        return ttm;
    }

// Pull ONLY the date from an existing tm struct (ignoring the time)
    TimeTm makeDate(const TimeTm &t) {
        TimeTm ttm = {0};
        ttm.tm_mon = t.tm_mon;
        ttm.tm_mday = t.tm_mday;
        ttm.tm_year = t.tm_year;
        //time_t raw = mktime(&ttm);
        //Time *tm = localtime(&raw);
        //return *tm;
        return ttm;
    }

    TimeTm makeDateTime(int month, int day, int year, int hour, int minute, int second) {
        TimeTm ttm = {0};
        ttm.tm_mon = month - 1;
        ttm.tm_mday = day;
        ttm.tm_year = year - 1900;
        ttm.tm_hour = hour;
        ttm.tm_min = minute;
        ttm.tm_sec = second;
        //time_t raw = mktime(&ttm);
        //Time *tm = localtime(&raw);
        //return *tm;
        return ttm;
    }

    TimeTm makeDateTime(const TimeTm &t) {
        TimeTm ttm = {0};
        ttm.tm_mon = t.tm_mon;
        ttm.tm_mday = t.tm_mday;
        ttm.tm_year = t.tm_year;
        ttm.tm_hour = t.tm_hour;
        ttm.tm_min = t.tm_min;
        ttm.tm_sec = t.tm_sec;
        //time_t raw = mktime(&ttm);
        //Time *tm = localtime(&raw);
        //return *tm;
        return ttm;
    }

    TimeTm to_datetime(const string &date_str, const string &time_str) {
        auto dparts = tools::split(date_str, '/');
        int month = atoi(dparts[0].c_str());
        int day = atoi(dparts[1].c_str());
        int year = atoi(dparts[2].c_str());
        auto tparts = tools::split(time_str, ':');
        int hour = atoi(tparts[0].c_str());
        int minute = atoi(tparts[1].c_str());
        int second = atoi(tparts[2].c_str());
        return makeDateTime(month, day, year, hour, minute, second);
    }

// This works like a C# compare (returns -1, 0, 1) but should probably create operator overloads
// TODO: create operator overloads for <, >, ==, etc...
    int compare(const TimeTm &t1, const TimeTm &t2) {
        time_t raw1 = to_rawtime(t1);
        time_t raw2 = to_rawtime(t2);
        if (raw1 < raw2)
            return -1;
        else if (raw1 > raw2)
            return 1;
        else
            return 0;
    }

// Are the dates in two Time structs equal (ignoring time)?
    bool dateEquals(const TimeTm &t1, const TimeTm &t2) {
        return (t1.tm_year == t2.tm_year && t1.tm_mon == t2.tm_mon && t1.tm_mday == t2.tm_mday);
    }

// Are the times in two Time structs equal (ignoring date)?
    bool timeEquals(const TimeTm &t1, const TimeTm &t2) {
        return (t1.tm_hour == t2.tm_hour && t1.tm_min == t2.tm_min && t1.tm_sec == t2.tm_sec);
    }

// Same month/year for two Time structs?
    bool same_month(const TimeTm &t1, const TimeTm &t2) {
        return (t1.tm_year == t2.tm_year && t1.tm_mon == t2.tm_mon);
    }

} // namespace TimeTm