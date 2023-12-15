//
// Created by 徐浩闻 on 2023/12/15.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int> &neededTime) {
        int n = neededTime.size();
        vector<int> dp(n + 5, 0);
        int last_idx = 0;
        for (int i = 1; i < n; i++) {
            if(colors[i]!=colors[i-1]) {
                dp[i] = dp[i-1];
                last_idx = i;
            }else {
                if(neededTime[last_idx] < neededTime[i]) {
                    dp[i] =dp[i-1]+neededTime[last_idx];
                    last_idx = i;
                } else{
                    dp[i] = dp[i-1]+ neededTime[i];
                }
            }
        }
        return dp[n-1];

    }
};

int main() {


}