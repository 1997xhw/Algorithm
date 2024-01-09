//
// Created by 徐浩闻 on 2024/1/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
    const int mod = 1e9 + 7;
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        vector<int> powers;
        vector<int> su;
        su.push_back(0);
        int i = 0;
        while (n) {
            if (n & 1 == 1) {
                powers.emplace_back(i);
                su.emplace_back(su[su.size() - 1] + i);
            }
            i++;
            n >>= 1;
        }
        vector<int> ans;
        for (auto &item: queries) {
            int l = item[0], r = item[1] + 1;
            int power = su[r] - su[l];
            long long tmp = 1;
            while (power) {
                tmp <<= 1;
                tmp %= mod;
                power--;
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};

int main() {
    int n = 10000000;
    vector<vector<int>> queries = {{0, 1},
                                   {2, 2},
                                   {0, 3},
                                   {2, 7}};
    Solution s;
    vector<int> ans = s.productQueries(n, queries);
    for (auto &item: ans) {
        cout << item << " ";
    }

}