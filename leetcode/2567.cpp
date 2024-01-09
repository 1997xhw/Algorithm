//
// Created by 徐浩闻 on 2024/1/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min(min(nums[n - 3] - nums[0], nums[n - 2] - nums[1]), nums[n - 1] - nums[2]);
    }
};

int main() {
    vector<int> nums = {59, 27, 9, 81, 33};
    Solution s;
    cout << s.minimizeSum(nums);

}