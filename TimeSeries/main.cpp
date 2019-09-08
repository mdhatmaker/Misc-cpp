#include "BarData.h"
#include "tools.h"
#include "Contract.h"
#include "HistoricalData.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <fstream>


using namespace std;


/*vector<Time> get_matching_times(hg_contract, date) {
    // look at closing bar times on the given date for HG and LME copper and return a vector of the
    // times for which we have data in both HG and LME that match up
}*/

// Process the 5 main HG months (H, K, N, U, Z) for the given year (specified as YYYY or YY)
void create_for_year(Historical &hist, string folder, int year) {
    string yy = tail(to_string(year), 2);
    hist.create_from_file(folder, "QHGH" + yy, 0);
    hist.create_from_file(folder, "QHGK" + yy, 0);
    hist.create_from_file(folder, "QHGN" + yy, 0);
    hist.create_from_file(folder, "QHGU" + yy, 0);
    hist.create_from_file(folder, "QHGZ" + yy, 0);
}

int main() {
    const string LME = "M.CU3=LX";

    //string folder = "/Users/michael/CLionProjects/TimeSeries/data/";
    string folder = "D:\\Users\\mhatmaker\\Dropbox\\ALVIN\\cpp\\TimeSeries\\data\\";
    //string folder = "C:\\Users\\Michael\\projects\\TimeSeries\\data\\";

    Historical hist;

    // UPDATE: I re-downloaded the Multichart historical data with time set to "local", so no adjustment necessary.
    // Adjust times on LME data points by 6 hours (time is "exchange time")
    // Adjust time on HG data points by 1 hour (time is "exchange time")
    hist.create_from_file(folder, LME, 0);

    // previous years
    create_for_year(hist, folder, 10);
    create_for_year(hist, folder, 11);
    create_for_year(hist, folder, 12);
    create_for_year(hist, folder, 13);
    create_for_year(hist, folder, 14);
    create_for_year(hist, folder, 15);
    create_for_year(hist, folder, 16);

    // current year
    hist.create_from_file(folder, "QHGF17", 0);
    hist.create_from_file(folder, "QHGG17", 0);
    hist.create_from_file(folder, "QHGH17", 0);
    hist.create_from_file(folder, "QHGJ17", 0);
    hist.create_from_file(folder, "QHGK17", 0);
    hist.create_from_file(folder, "QHGM17", 0);
    hist.create_from_file(folder, "QHGN17", 0);
    hist.create_from_file(folder, "QHGQ17", 0);
    hist.create_from_file(folder, "QHGU17", 0);

    // calendar spreads
    hist.create_from_file(folder, "QHGU16-QHGV16", 0);
    hist.create_from_file(folder, "QHGU16-QHGZ16", 0);
    hist.create_from_file(folder, "QHGZ16-QHGF17", 0);
    hist.create_from_file(folder, "QHGZ16-QHGH17", 0);
    hist.create_from_file(folder, "QHGH17-QHGJ17", 0);
    hist.create_from_file(folder, "QHGH17-QHGK17", 0);
    hist.create_from_file(folder, "QHGK17-QHGM17", 0);
    hist.create_from_file(folder, "QHGK17-QHGN17", 0);
    hist.create_from_file(folder, "QHGN17-QHGQ17", 0);
    hist.create_from_file(folder, "QHGN17-QHGU17", 0);
    //hist.create_calendar_spread("QHGZ16", "QHGF17");
    //hist.create_calendar_spread("QHGH17", "QHGJ17");

    //hist["QHGH17-QHGJ17_implied"].print();
    //hist[LME].print();
    //return 0;

    // Create output files
    ofstream copper_spread_file, calendar_spread_file, premium_discount_file;
    copper_spread_file.open (folder + "copper_spread.csv");
    calendar_spread_file.open(folder + "calendar_spread.csv");
    premium_discount_file.open(folder + "premium_discount.csv");

    // Output column headers in the premium/discount file and copper spread file
    premium_discount_file << "<Date>, <Time>, <HG>, <LME>, <Spread>, <Calendar>, <Discount/Premium>, <CalendarSymbol>" << endl;
    copper_spread_file << "<Date>, <Time>, <HG>, <LME>, <Spread>, <CalendarSymbol>" << endl;

    // MAIN loop
    //for (auto date : data["LME"].unique_dates()) {
    for (auto date : hist[LME].unique_dates()) {
        SimpleTime hg_front = CME::get_front_month_hg(date);
        SimpleTime hg_back = CME::get_spread_back_month_hg(date);

        // HACK: if our back month is same as front month, just increment the back month
        if (hg_front.same_month(hg_back))
            hg_back.add_month(+1);

        string base_symbol = "QHG";
        string contract_symbol = CME::get_contract_symbol(base_symbol, hg_front);
        string spread_symbol = CME::get_spread_contract_symbol(base_symbol, hg_front, hg_back);

        SimpleTime expiry = CME::get_expiration_date_hg(hg_front.month, hg_front.year);
        //cout << expiry << endl;

        // Get the time series "bars" for the given date (for HG outright, LME, HG calendar spread)
        //auto bars_lme = data["LME"].get_bars_for_date(date);
        auto bars_lme = hist[LME].get_bars_for_date(date);
        auto bars_hg = hist[contract_symbol].get_bars_for_date(date);
        auto bars_hg_spread = hist[spread_symbol].get_bars_for_date(date);

        // return only the bar data for which bars exist at same time in both HG and LME
        for (BarData hgBar : bars_hg) {
            for (BarData lmeBar : bars_lme) {
                if (hgBar.time == lmeBar.time) {
                    //cout << contract_symbol << " " << hgBar << "\n";
                    //cout << "LME " << lmeBar << "\n";
                    double spreadPrice = hgBar.close - .000454 * lmeBar.close;    // multiply by 100 to get easier-to-read data
                    cout << hgBar.time.to_csv_string() << hgBar.close << "," << lmeBar.close << "," << spreadPrice * 100 << "," << spread_symbol << endl;
                    copper_spread_file << hgBar.time.to_csv_string() << hgBar.close << "," << lmeBar.close << "," << spreadPrice * 100 << "," << spread_symbol << endl;

                    for (BarData spreadBar : bars_hg_spread) {
                        if (hgBar.time == spreadBar.time) {
                            //cout << to_csv_string(hgBar.time) << spreadBar.close << endl;
                            calendar_spread_file << hgBar.time.to_csv_string() << spreadBar.close << endl;
                            premium_discount_file << hgBar.time.to_csv_string() << hgBar.close << "," << lmeBar.close << "," << spreadPrice << "," << spreadBar.close << "," << (spreadPrice - spreadBar.close) << "," << spread_symbol << endl;
                            break;
                        }
                    }

                    break;
                }
            }
        }

    } // MAIN loop

    // Close output files
    copper_spread_file.close();
    calendar_spread_file.close();
    premium_discount_file.close();

    return 0;
}