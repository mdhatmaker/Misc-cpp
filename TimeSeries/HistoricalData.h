//
// Created by Michael Hatmaker on 4/29/17.
//

#ifndef TIMESERIES_HISTORICALDATA_H
#define TIMESERIES_HISTORICALDATA_H

#include "tools.h"
#include "BarData.h"
#include "SimpleTime.h"
#include <set>

using namespace tools;


class HistoricalData {
public:
    HistoricalData() { }
    HistoricalData(string symbol) : m_symbol(symbol) { }

    //bool data_exists_for_time(SimpleDate, SimpleTime);
    //void add(const BarData<T> &bar);
    void add(SimpleTime t, double o, double h, double l, double c, int volume);
    BarData operator[](int i) { return m_bar_vector[i]; }
    //BarData get(Time id) { return m_bar_map[id]; }
    void print();

    int size() { return m_bar_vector.size(); }
    const set<SimpleTime, SimpleTime_compare>& unique_dates() { return m_unique_dates; };

    bool get_bar_for_time(SimpleTime t, BarData &result);
    vector<BarData> get_bars_for_date(SimpleTime dt);

    //void add_hour_to_all_times(int hour_delta);

private:
    string m_symbol;
    vector<BarData> m_bar_vector;
    set<SimpleTime, SimpleTime_compare> m_unique_dates;
};


class Historical {
public:
    Historical() { }

    void read_from_file(HistoricalData &item, string filename, int hour_delta);
    void create_from_file(string folder, string symbol, int hour_delta);
    void create_calendar_spread(string front_symbol, string back_symbol);
    HistoricalData& operator[](string symbol) { return m_data[symbol]; }
private:
    map<string, HistoricalData> m_data;
};


#endif //TIMESERIES_HISTORICALDATA_H
