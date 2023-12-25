//
// Created by 徐浩闻 on 2023/12/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + pow(-1, i % 2) * nums[i-1];
        }
        int res = 0;
        for (int i = 1; i <=n; i++) {
            if(dp[i - 1] == dp[n] - dp[i])
                res ++;
        }
        return res;

    }
};

int main() {
//    vector<int> nums = {2, 1, 6, 4};
    vector<int> nums = {1, 1, 1};
    Solution s;
     cout << s.waysToMakeFair(nums);
    cout << " " << endl;

}