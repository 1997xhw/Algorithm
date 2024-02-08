//
// Created by 徐浩闻 on 2024/2/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        auto getSum = [&](char c) -> int {
            int cnt = 0, ans = 0;
            vector<int> f(n);
            for (int i = 0; i < n; i++) {
                if (answerKey[i] == c) f[cnt++] = i;
                if (cnt <= k) ans = i + 1;
                else ans = max(ans, i - f[cnt - k - 1]);
            }
            return ans;
        };
        return max(getSum('T'), getSum('F'));
    }
};

int main() {


}