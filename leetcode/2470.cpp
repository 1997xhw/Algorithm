//
// Created by 徐浩闻 on 2023/12/12.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int subarrayLCM(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long l = nums[i];
            for (int j = i; j < n; j++) {
                long long g = gcd(nums[j], l);
                l = l / g * nums[j];
                if (l == k) ans++;
                else if (l > k) break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

}