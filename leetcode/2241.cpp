//
// Created by 徐浩闻 on 2024/1/22.
//
#include "bits/stdc++.h"

using namespace std;

class ATM {
public:
    vector<pair<int, int>> mm{{20, 0}, {50, 0}, {100, 0}, {200, 0}, {500, 0}};

    ATM() {

    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            mm[i].second += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<pair<int, int>> tmp = mm;
        vector<int> res = {0, 0, 0, 0, 0};
        for (int i = 4; i >= 0; i--) {
            if (tmp[i].second != 0) {
                int n = amount / tmp[i].first;
                n = min(n, tmp[i].second);
                amount -= n * tmp[i].first;
                tmp[i].second -= n;
                res[i]+=n;
            }
        }
        if (amount == 0) {
            mm = tmp;
            return res;
        } else return {-1};
    }
};

int main() {


}