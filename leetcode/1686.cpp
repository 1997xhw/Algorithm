//
// Created by 徐浩闻 on 2024/2/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
        int n = aliceValues.size();
        vector<pair<int, pair<int, int>>> mp;
        for (int i = 0; i < n; i++) {
            mp.push_back({aliceValues[i] + bobValues[i], {aliceValues[i], bobValues[i]}});
        }
        sort(mp.begin(), mp.end(),
             [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) { return a.first > b.first; });
        int ans_a = 0, ans_b = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 ==0)
                ans_a += mp[i].second.first;
            else
                ans_b += mp[i].second.second;
        }
        if(ans_a > ans_b) return 1;
        else if (ans_b > ans_a) return -1;
        else
            return 0;
    }
};

int main() {


}