#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;


struct Bid {
    int userId;
    int shares;
    int price;
    int timestamp;
};

//int* getUnallottedUsers(int bids_rows, int bids_columns, int** bids, int totalShares, int* result_count);

vector<Bid> bidsForPrice(const vector<Bid> &bids, int price) {
    vector<Bid> ret;
    auto it = copy_if(bids.begin(), bids.end(), ret.begin(),
            [price](Bid b) { return b.price == price; });
    return ret;
}

bool cmd(const Bid & b1, const Bid & b2)
{
    return b1.timestamp < b2.timestamp;
}

vector<int> getUnallottedUsers(vector<Bid> bids, int totalShares) {
    vector<int> ret;                            // return this vector as function result
    map<int,vector<Bid>,greater<int>> m;        // bids by price (sorted max price to min price)

    // After this loop, we will have an initial vector of all user ids AND a map of bids by price
    for (auto &b: bids) {
        ret.push_back(b.userId);
        
        if (m.find(b.price) == m.end()) {       // key does NOT exist
            m[b.price] = vector<Bid> { b };
        }
        else {
            m[b.price].push_back(b);
        }        
    }

    int shares = totalShares;
    for (auto &kv: m) {
        cout << "price: " << kv.first << "\n";
        sort(kv.second.begin(), kv.second.end(), cmd);

        int shares_at_price = 0;
        for (auto &bap: kv.second)
            shares_at_price += bap.shares;

        if (shares >= shares_at_price) {
            ret.erase( remove_if(ret.begin(), ret.end(), [](int i) { return true; }), ret.end() );
        }

        for (auto &xx: kv.second) {
            cout << xx.timestamp << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return ret;
}


int main()
{
    vector<Bid> v;

    Bid b1 {1, 2, 5, 100};
    Bid b2 {2, 3, 4, 99};
    Bid b3 {3, 2, 4, 101};
    Bid b4 {4, 1, 6, 97};
    Bid b5 {5, 3, 2, 103};

    v.push_back(b1);
    v.push_back(b2);
    v.push_back(b3);
    v.push_back(b4);
    v.push_back(b5);

    vector<int> res = getUnallottedUsers(v, 6);
    for (auto id: res) {
        cout << id << "\n";
    }

}