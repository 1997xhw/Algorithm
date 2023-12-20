//
// Created by 徐浩闻 on 2023/12/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size(), sum;
        int p = accumulate(nums.begin(), nums.end(), target);
        cout << p << endl;
        if (p < 0 || p % 2) return 0;
        p /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= p;j++) {
                if (j < nums[i]) dp[i + 1][j] = dp[i][j];
                else {
                    dp[i + 1][j] = dp[i][j] + dp[i][j - nums[i]];
                }
            }
        }
        return dp[n][p];
    }
};

int main() {


}