//
// Created by 徐浩闻 on 2023/12/22.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lengthOfLIS1(vector<int> &nums) {
        int len = nums.size();
        int dp[len];
        for (int i = 0; i < len; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
        }
        return *max_element(dp, dp + len);
    }

    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        vector<int> g;
        for (auto &n: nums) {
            int l = 0, r = g.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (g[mid] < n) l = mid + 1;
                else r = mid;
            }
            if (l == g.size()) g.emplace_back(n);
            else g[l] = n;
        }
        return g.size();
    }
};

int main() {
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    Solution s;
    cout << s.lengthOfLIS(nums);

}