//
// Created by Michael Hatmaker on 4/28/17.
//

#include "BarData.h"

#include <iostream>

using namespace std;

/*template <typename T>
void Bars<T>::add(const BarData<T> bar) {
    m_bar_vector.push_back(bar);
    m_bar_map[bar.id] = bar;
}

template <typename T>
Bars<T> Bars<T>::create_random_bars(int count, float open, int max_range) {
    Bars bars;
    for (int i = 0; i < count; ++i) {
        double high = open + rand() % (max_range / 2);
        double low = open - rand() % (max_range / 2);
        double close = low + rand() % int(high - low);
        int volume = rand() % 500;
        BarData<T> bar {to_string(i), open, high, low, close, volume};
        bars.add(bar);
        open = close;
    }
    return bars;
}

template <typename T>
void Bars<T>::print() {
    for (auto bar : m_bar_vector) {
        cout << bar.id << ": " << bar.open << "," << bar.high << "," << bar.low << "," << bar.close << "," << bar.volume << endl;
    }
}*/

