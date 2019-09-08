//
// Created by Michael Hatmaker on 4/29/17.
//

#ifndef TIMESERIES_CONTRACT_H
#define TIMESERIES_CONTRACT_H

#include "tools.h"
#include "SimpleTime.h"

using namespace tools;

enum class Exchange { CME, LME };

enum class MonthCode { F=1, G, H, J, K, M, N, Q, U, V, X, Z };

class Contract {
public:
    static string to_string(const MonthCode);
    static string to_string(const MonthCode, const int year);
    static string to_MYY(SimpleTime m1);
    static MonthCode get_month_code(SimpleTime m1);
};

class CME {
public:

    static SimpleTime get_front_month_hg(SimpleTime dt);
    static SimpleTime get_spread_back_month_hg(const SimpleTime &dt);

    static string get_contract_symbol(const string &symbol_base, SimpleTime m1);
    static string get_spread_contract_symbol(const string &symbol_base, SimpleTime m1, SimpleTime m2);

    static SimpleTime get_expiration_date_hg(int m, int y);

    static bool is_business_day(const SimpleTime &dt);
private:
    //Exchange m_exchange;
    //string m_symbol;
};


#endif //TIMESERIES_CONTRACT_H
