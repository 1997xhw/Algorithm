//
// Created by 徐浩闻 on 2024/1/31.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
        unordered_map<int, int> mp;
        for (auto &item: reservedSeats)
            mp[item[0]] |= (1 << (item[1]-1));
//            seats[item[0]] += (1 << item[1]-1);
        int ans = 0;
        ans+= (n-mp.size())*2;
        for (auto it = mp.begin(); it!=mp.end(); it++) {
            int tmp = it->second;
            if ((510 & tmp) == 0) ans += 2;
            else if ((tmp & 480) == 0 || (tmp & 120 )== 0 || (tmp & 30) == 0) ans += 1;
        }
        return ans;
    }
};

int main() {
    cout << (510 & 513);

}