//
// Created by 徐浩闻 on 2023/12/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int dp[coins.size() + 1][amount + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0]= 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                if (j < coins[i])
                    dp[i + 1][j] = dp[i][j];
                else {
                    dp[i + 1][j] = min(dp[i][j], dp[i+1][j - coins[i]] + 1);
                }
            }
        }
        int ans = dp[coins.size()][amount];
        return ans < 0x3f3f3f3f ? ans : -1;
    }
};

int main() {


}