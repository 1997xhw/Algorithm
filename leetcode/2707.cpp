//
// Created by 徐浩闻 on 2024/1/9.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        int n = s.length();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + 1;
            for (int j = 0; j <= i; j++) {
                if (st.count(s.substr(j, i - j + 1))) {
                    dp[i + 1]  = min(dp[i+1], dp[j]);
                }
            }
        }
        return dp[n];
    }
};

int main() {


}