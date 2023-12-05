//
// Created by 徐浩闻 on 2023/11/27.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target) ans++;
            }
        }
        return ans;

    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 1, 2, 3, 1};
    cout << s.countPairs(nums, 2) << endl;

}