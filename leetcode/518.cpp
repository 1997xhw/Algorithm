//
// Created by 徐浩闻 on 2023/12/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int dp[coins.size() + 1][amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= coins.size(); i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++) {

                dp[i][j] = dp[i-1][j];
                if(j >= coins[i-1]) {
                    dp[i][j] +=dp[i][j - coins[i-1]];
                }
            }
        }
        int ans = dp[coins.size()][amount];
        return ans;
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    Solution s;
    cout << s.change(5, coins);

}