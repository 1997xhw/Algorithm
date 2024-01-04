//
// Created by 徐浩闻 on 2024/1/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int subarrayGCD(vector<int> &nums, int k) {
        function<int(int, int)> gcd = [&](int a, int b) -> int {
            return b ? gcd(b, a % b) : a;
        };

        int n = nums.size(), ans = 0;
        for (int l = 0, r = 0, i = 1; i <= n; ++i) {
            if (nums[i - 1] % k != 0) {
                l = r = i;
                continue;
            }
            while (l < i && gcd(l, i) < k)
                ++l;
            r = max(l, r);
            while (r < i && gcd(r, i) <= k)
                ++r;
            ans += r - l;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {9, 3, 1, 2, 6, 3};
    int k = 3;
    cout << s.subarrayGCD(nums, k);

}