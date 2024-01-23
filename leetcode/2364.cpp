//
// Created by 徐浩闻 on 2024/1/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int> &nums) {
        int n = nums.size();
        long long ans = 1L * (n - 1) * n / 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i] - i;
            ans -= mp[tmp];
            mp[tmp]++;
        }
        return ans;
    }
};

int main() {


}