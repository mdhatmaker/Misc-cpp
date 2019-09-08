//
// Created by Michael Hatmaker on 4/28/17.
//

#ifndef TIMESERIES_BARDATA_H
#define TIMESERIES_BARDATA_H

#include "tools.h"
#include "SimpleTime.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct BarData {
    SimpleTime time;
    double open;
    double high;
    double low;
    double close;
    int volume;

    friend ostream& operator<<(ostream& os, const BarData& bar) {
        os << bar.time << "  O:" << bar.open << "  H:" << bar.high << "  L:" << bar.low << "  C:" << bar.close << "  V:" << bar.volume;
        return os;
    }
};

/*template <typename T>
class Bars {
public:
    Bars() { }
public:
    void add(const BarData<T> bar);
    BarData<T> operator[](int i) { return m_bar_vector[i]; }
    BarData<T> get(string id) { return m_bar_map[id]; }
    void print();

    int size() { return m_bar_vector.size(); }

    static Bars create_random_bars(int count, float open = 5000, int max_range = 100);

private:
    vector<BarData<T>> m_bar_vector;
    map<string, BarData<T>> m_bar_map;
};*/

#endif //TIMESERIES_BARDATA_H
