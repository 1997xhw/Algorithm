//
// Created by 徐浩闻 on 2023/12/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        if (difference < 0) {
            difference *= -1;
            reverse(arr.begin(), arr.end());
        }
        int n = arr.size();
        unordered_map<int, int> hs;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][1] = 1;
        hs[arr[0]] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = 1;
            int prev = arr[i] - difference;
            if (hs.find(prev) != hs.end()) dp[i][1] = max(dp[i][1], dp[hs[prev]][1] + 1);
            hs[arr[i]] = i;
        }
        return max(dp[n - 1][0], dp[n - 1][1]);


    }
};

int main() {
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    Solution s;
    cout << s.longestSubsequence(arr, -2);

}