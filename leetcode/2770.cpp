//
// Created by 徐浩闻 on 2023/12/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int> &nums, int target) {

        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[nums.size() - 1] < 0 ? -1 : dp[nums.size() - 1];
    }
};

int main() {


}