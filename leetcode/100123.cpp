//
// Created by 徐浩闻 on 2023/12/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxFrequencyScore(vector<int> &nums, long long k) {
        int n = nums.size();
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        long long ss[n + 1];
        ss[0] = 0;
        for (int i = 1; i <= n; i++) {
            ss[i] = ss[i - 1] + nums[i];
        }
        auto countFee = [&](int l, int r) {
            int mid = (l + r) / 2;
            return ((1LL * nums[mid] * (mid - l + 1) - (ss[mid] - ss[l - 1])) +
                    ((ss[r] - ss[mid]) - 1LL * nums[mid] * (r - mid)));
        };
        int ans = 0;
        for (int i = 1, j = 1; i <= n; i++) {
            while (j <= i && countFee(j, i) > k) j++;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

int main() {


}