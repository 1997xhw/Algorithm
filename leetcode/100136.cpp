//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int modPow(long long base, int exponent, int mod) {
    base %= mod;
    long long result = 1;
    while (exponent > 0) {
    if (exponent % 2 == 1)
    result = (result * base) % mod;
    base = (base * base) % mod;
    exponent /= 2;
    }
    return result;
    }

    int numberOfGoodPartitions(vector<int> &nums) {
    unordered_map<int, int> cut;
    for (int i = 0; i < nums.size(); ++i) {
    cut[nums[i]] = i;
    }
    int ans = 0, lit = 0;
    for (int i = 0; i < nums.size(); ++i) {
    lit = max(lit, cut[nums[i]]);
    if (lit == i) ans++;
    }
    return modPow(2, ans - 1, 1e9 + 7);

    }
};

int main() {

    vector<int> nums = {};
    Solution s;
    cout << s.numberOfGoodPartitions(nums);
}