//
// Created by 徐浩闻 on 2024/1/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        long long ans = 0;
        if (arr[0] % 2 == 0) {
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1;
            ans++;
        }

        for (int i = 1; i < n; i++) {
            if (arr[i] % 2 == 1) {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][0];
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }
            ans += dp[i][0];
            ans %= 1000000007;
        }
        return ans;
    }
};

int main() {


}