//
// Created by 徐浩闻 on 2023/12/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long tmp = 0;
        for (auto &item: word) {
            long long num = item - '0';
            tmp = tmp * 10 + num;
            if (tmp % m != 0) {
                ans.emplace_back(0);
                tmp %= m;
            } else {
                tmp = 0;
                ans.emplace_back(1);
            }
        }
        return ans;
    }
};

int main() {

    Solution s;
    vector<int> ans = s.divisibilityArray("8917171717276217174131", 17);
    for (auto &item: ans) {
        cout << item << " ";
    }
}