//
// Created by 徐浩闻 on 2023/11/27.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {

public:
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int> &arr) {
        int len = arr.size();
        stack<int> stk;
        vector<int> minArrL(len, -1), minArrR(len, len);
        for (int i = 0; i < len; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            if (!stk.empty()) minArrL[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = len - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
            if (!stk.empty()) minArrR[i] = stk.top();
            stk.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < len; i++) {
            ans += 1LL * (i - minArrL[i]) * (minArrR[i] - i) * arr[i];
            ans %= MOD;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {11,81,94,43,3};
    cout << s.sumSubarrayMins(v) << endl;

}