//
// Created by 徐浩闻 on 2023/12/17.
//
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int ans = INT_MAX;
        vector<int> dp(cost.size()+5, 0);
        for(int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};

int main() {


}