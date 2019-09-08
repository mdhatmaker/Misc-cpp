//
// Created by Michael Hatmaker on 5/5/2017.
//

#ifndef TIMESERIES_TIMETM_H
#define TIMESERIES_TIMETM_H

#include <ctime>
#include <string>


using namespace std;

typedef struct tm TimeTm;

namespace Time
{
    TimeTm makeDate( int month, int day, int year );
    TimeTm makeDate( const TimeTm &t );
    TimeTm makeDateTime( int month, int day, int year, int hour, int minute, int second );
    TimeTm makeDateTime( const TimeTm &t);

    TimeTm add_month(const TimeTm &t, int mon_delta);
    TimeTm add_day(const TimeTm &t, int day_delta);
    TimeTm add_hour(const TimeTm &t, int hour_delta);

    int days_between(TimeTm *tsa, TimeTm *tsb);
    int days_of_month(int m, int y);
    int days_of_year(int y);

    bool is_weekend(TimeTm t);             // Sat or Sun
    bool is_weekday(TimeTm t);             // Mon through Fri

    string to_string(const TimeTm &t);
    string to_csv_string(const TimeTm &t);    // comma-delimeted date/time that will import into multichart

    TimeTm to_datetime(const string &date_str, const string &time_str);   // parse date and time strings
    time_t to_rawtime(const TimeTm &t);

    bool dateEquals(const TimeTm &t1, const TimeTm &t2);                    // do dates match on two Time structs
    bool timeEquals(const TimeTm &t1, const TimeTm &t2);                    // do times match on two Time structs
    bool same_month(const TimeTm &t1, const TimeTm &t2);                    // does month/year match on two Time structs
    int compare(const TimeTm &t1, const TimeTm &t2);

    struct Time_compare {
        bool operator() (const TimeTm& lhs, const TimeTm& rhs) const {
            return to_rawtime(lhs) < to_rawtime(rhs);
        }
    };


}


#endif //TIMESERIES_TIMETM_H
