//
// Created by Michael Hatmaker on 4/29/17.
//

#include "HistoricalData.h"

#include <string>
#include <iostream>
#include <fstream>

/*double get_bar(string date, string time) {
    // returns price for LME copper at given date/time
}*/



void Historical::create_from_file(string folder, string symbol, int hour_delta = 0) {
    string filename = folder + symbol + ".txt";
    read_from_file(m_data[symbol], filename, hour_delta);
}

void Historical::read_from_file(HistoricalData &data, string filename, int hour_delta = 0) {
    cout << "[" << filename << "]   ";
    int count = 0;
    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        getline(myfile, line);          // skip first (column header) line of file
        while (getline(myfile, line))
        {
            ++count;                                        // keep track of our read line count
            vector<string> v = tools::split(line, ',');
            //Time t = tools::to_datetime(v[0], v[1]);
            SimpleTime t = makeDateTime(v[0], v[1]);
            double open = atof(v[2].c_str());
            double high = atof(v[3].c_str());
            double low = atof(v[4].c_str());
            double close = atof(v[5].c_str());
            int volume = atoi(v[6].c_str());

            // Use the following lines to break at a certain date
            //if (t.month == 3 && t.day == 13)
            //    cout << "hello" << endl;

            if (hour_delta != 0)
                t.add_hour(hour_delta);
            data.add(t, open, high, low, close, volume);
        }
        myfile.close();
        cout << count << " lines read" << endl;
    }
    else
        cout << "Unable to open file: " << filename << endl;
}

void Historical::create_calendar_spread(string front, string back) {
    string spread_symbol = front + "-" + back + "_implied";
    BarData bbar;
    for (int i = 0; i < m_data[front].size(); ++i) {
        BarData fbar = m_data[front][i];
        if (m_data[back].get_bar_for_time(fbar.time, bbar)) {
            double close_price = fbar.close - bbar.close;
            //cout << "front: " << fbar << "      back: " << bbar << "    price=" << close_price << endl;
            m_data[spread_symbol].add(fbar.time, 0, 0, 0, close_price, 0);
        }
    }
}

void HistoricalData::print() {
    for (auto bar : m_bar_vector) {
        cout << bar.time << ": " << bar.open << "," << bar.high << "," << bar.low << "," << bar.close << "," << bar.volume << endl;
    }
}

void HistoricalData::add(SimpleTime t, double open, double high, double low, double close, int volume) {
    BarData bar { t, open, high, low, close, volume };
    m_bar_vector.push_back(bar);
    SimpleTime date_only = makeDate(t);
    m_unique_dates.insert(date_only);
}

/*const set<Time, tools::Time_compare>& HistoricalData::unique_dates() {
    set<Time, tools::Time_compare> unique_dates;
    for (BarData bar : m_bar_vector) {
        Time date_only = tools::makeDate(bar.time);
        unique_dates.insert(date_only);
    }
    return unique_dates;
}*/

bool HistoricalData::get_bar_for_time(SimpleTime t, BarData &result) {
    for (BarData bar : m_bar_vector) {
        if (bar.time == t) {
            result = bar;
            return true;
        }
    }
    return false;
}

vector<BarData> HistoricalData::get_bars_for_date(SimpleTime dt) {
    vector<BarData> v;
    for (BarData bar : m_bar_vector) {
        if (dt.dateEquals(bar.time))
            v.push_back(bar);
    }
    return v;
}

/*void HistoricalData::add_hour_to_all_times(int hour_delta) {
    for (BarData& bar : m_bar_vector) {
        bar.time = add_hour(bar.time, hour_delta);
    }
}*/