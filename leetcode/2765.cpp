//
// Created by 徐浩闻 on 2023/12/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int flag = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == flag) {
                dp[i] = dp[i - 1] + 1;
                flag *= -1;
            } else if (nums[i] - nums[i - 1] == 1) {
                flag = -1;
                dp[i] = 2;
            } else {
                flag = 1;
            }
        }
        int res = 0;
        for (auto &item: dp) res = max(res, item);
        if (res > 1) return res;
        return -1;
    }
};

int main() {


}
