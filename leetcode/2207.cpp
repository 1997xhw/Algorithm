//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        string nt = text;

        long long ans = 0, cnt0 = 0, cnt1 = 0;
        for (int i = nt.length() - 1; i >= 0; i--) {
            cnt0 += nt[i] == pattern[0];
            if (nt[i] == pattern[0]) {
                ans += cnt1;
            }
            cnt1 += nt[i] == pattern[1];
        }
        return ans + max(cnt1, cnt0);
    }
};

int main() {
    Solution s;
    cout <<s.maximumSubsequenceCount("abdcdbc", "ac");

}

