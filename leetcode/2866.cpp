//
// Created by 徐浩闻 on 2023/12/21.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int> &maxHeights) {
        int n = maxHeights.size();

        auto gao = [&](long long *f) {
            stack<int> stk;
            for (int i = 0; i < n; i++) {
                while (!stk.empty() && maxHeights[stk.top()] >= maxHeights[i]) stk.pop();
                if (stk.empty()) f[i] = 1LL * maxHeights[i] * (i + 1);
                else f[i] = f[stk.top()] + 1LL * maxHeights[i] * (i - stk.top());
                stk.push(i);
            }
        };

        long long f[n];
        gao(f);
        long long g[n];
        reverse(maxHeights.begin(), maxHeights.end());
        gao(g);
        reverse(maxHeights.begin(), maxHeights.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, f[i] + g[n-1-i] - maxHeights[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> maxHeights = {3, 5, 3, 5, 1, 5, 4, 4, 4};
    Solution s;
    cout << s.maximumSumOfHeights(maxHeights);

}