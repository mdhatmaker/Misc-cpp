//
// Created by Michael Hatmaker on 4/29/17.
//

#include <cassert>
#include <iostream>
#include "Contract.h"


SimpleTime CME::get_front_month_hg(SimpleTime dt) {
    // Here are the front months we use for HG
    // H   K   N   U   Z
    // Mar May Jul Sep Dec

    //int year = dt.tm_year + 1900;
    SimpleTime expiry_mar = get_expiration_date_hg(3, dt.year);
    SimpleTime expiry_may = get_expiration_date_hg(5, dt.year);
    SimpleTime expiry_jul = get_expiration_date_hg(7, dt.year);
    SimpleTime expiry_sep = get_expiration_date_hg(9, dt.year);
    SimpleTime expiry_dec = get_expiration_date_hg(12, dt.year);

    expiry_mar.add_month(-1);
    expiry_may.add_month(-1);
    expiry_jul.add_month(-1);
    expiry_sep.add_month(-1);
    expiry_dec.add_month(-1);

    if (dt < expiry_mar) {
        return makeDate(3, 1, dt.year);
    }
    else if (dt < expiry_may) {
        return makeDate(5, 1, dt.year);
    }
    else if (dt < expiry_jul) {
        return makeDate(7, 1, dt.year);
    }
    else if (dt < expiry_sep) {
        return makeDate(9, 1, dt.year);
    }
    else if (dt < expiry_dec) {
        return makeDate(12, 1, dt.year);
    }
    else {
        return makeDate(3, 1, dt.year + 1);
    }
}

SimpleTime CME::get_spread_back_month_hg(const SimpleTime &dt) {
    // return “back month” (2nd contract in calendar spread) for the given date
    // I *think* this means date + 90 days (as a starting point), but again, this could take into account LME holidays, etc...
    //TimeTm lme_back_date = add_day(dt, +90);
    SimpleTime lme_back_date = SimpleTime(dt);
    lme_back_date.add_day(+90);
    lme_back_date.day = 1;                          // return the 1st day of the month
    return lme_back_date;
}

string CME::get_contract_symbol(const string &symbol_base, SimpleTime m1) {
    return symbol_base + Contract::to_MYY(m1);
}

string CME::get_spread_contract_symbol(const string &symbol_base, SimpleTime m1, SimpleTime m2) {
    return symbol_base + Contract::to_MYY(m1) + "-" + symbol_base + Contract::to_MYY(m2);
}

// expiration for HG is 3rd from last business day of the month
SimpleTime CME::get_expiration_date_hg(int month, int year) {
    int max_day = tools::get_max_day(month, year);
    //TimeTm last_day_of_month = makeDate(month, max_day, year);
    SimpleTime day(year, month, max_day);                           // start at last day of the month
    int count = 0;                                                  // count the number of business days encountered
    do {
        if (is_business_day(day))
            ++count;
        if (count < 3) day.add_day(-1);                             // move to previous day
    } while (count < 3);

    return day;
}

// TODO: also need to check for CME holidays here
bool CME::is_business_day(const SimpleTime &t) {
    return tools::is_weekday(t.month, t.day, t.year);
}

string Contract::to_string(const MonthCode m1, const int year1) {
    string year_str = std::to_string(year1);
    assert(year_str.length() == 4 || year_str.length() == 2);
    if (year_str.length() == 4)
        return to_string(m1) + year_str.substr(2);
    else if (year_str.length() == 2)
        return to_string(m1) + year_str;
}

string Contract::to_MYY(SimpleTime m1) {
    return to_string(get_month_code(m1), m1.year);
}

MonthCode Contract::get_month_code(SimpleTime m1) {
    return static_cast<MonthCode>(m1.month);
}

string Contract::to_string(const MonthCode m1) {
    switch (m1) {
        case MonthCode::F:
            return "F";
        break;
        case MonthCode::G:
            return "G";
        break;
        case MonthCode::H:
            return "H";
        break;
        case MonthCode::J:
            return "J";
        break;
        case MonthCode::K:
            return "K";
        break;
        case MonthCode::M:
            return "M";
        break;
        case MonthCode::N:
            return "N";
        break;
        case MonthCode::Q:
            return "Q";
        break;
        case MonthCode::U:
            return "U";
        break;
        case MonthCode::V:
            return "V";
        break;
        case MonthCode::X:
            return "X";
        break;
        case MonthCode::Z:
            return "Z";
            break;
    }
}