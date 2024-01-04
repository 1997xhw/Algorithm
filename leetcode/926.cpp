//
// Created by 徐浩闻 on 2024/1/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = dp[i - 1][0] + (s[i] == '1' ? 1 : 0);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + (s[i] == '0' ? 1 : 0));
        }
        return min(dp[len-1][0], dp[len-1][1]);
    }

    int minFlipsMonoIncr2(string s) {
        int cnt = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') cnt++;
            else {
                res = min(res + 1, cnt);
            }

        }
        return res;
    }
};

int main() {


}