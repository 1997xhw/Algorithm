//
// Created by 徐浩闻 on 2024/3/16.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target) {
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(target + 1, -0x3f3f3f3f));
        dp[0][0] = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i + 1][j] = dp[i][j];
                if (j - nums[i] >= 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - nums[i]] + 1);
            }
        }
        if (dp[len][target] > 0) return dp[len][target];
        return -1;
    }

    int lengthOfLongestSubsequenceV2(vector<int> &nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        int cnt = 0;
        for (auto &item: nums) {
            cnt = min(cnt + item, target);
            for (int j = cnt; j <= target; j++) {
                dp[j] = max(dp[j - item] + 1, dp[j]);
            }
        }
        return dp[target] > 0 ? dp[target] : -1;
    }
};

int main() {


}