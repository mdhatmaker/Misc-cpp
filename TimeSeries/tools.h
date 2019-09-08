//
// Created by Michael Hatmaker on 4/29/17.
//

#ifndef TIMESERIES_TOOLS_H
#define TIMESERIES_TOOLS_H

#include <string>
#include <vector>
#include <ctime>

using namespace std;

namespace tools
{

    template<typename Out>
    void split(const string &s, char delim, Out result);

    vector<string> split(const string &s, char delim);

    int get_max_day(int month, int year);
    //int get_year(const Time &t) { return t.tm_year + 1900; }
    int get_day_of_week(int month, int day, int year);

    bool is_leap_year(int y);
    bool is_weekday(int month, int day, int year);
    bool is_weekend(int month, int day, int year);

    string tail(string const& source, size_t const length);

}


#endif //TIMESERIES_TOOLS_H
