//
// Created by 徐浩闻 on 2023/12/3.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int> &coins, int target) {
        sort(coins.begin(), coins.end());
        long long x = 0;
        int addedCoins = 0;

        for (int coin: coins) {
            while (x < target && coin > x + 1) {
                addedCoins++;
                x += (x + 1);
            }
            x += coin;
            if (x >= target) {
                break;
            }
        }

        while (x < target) {
            addedCoins++;
            x += (x + 1);
        }

        return addedCoins;
    }
};

int main() {


}