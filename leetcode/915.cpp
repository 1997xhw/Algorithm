//
// Created by 徐浩闻 on 2023/11/29.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int> &nums) {
//        int[] smun = new int[nums.size() + 10];
        int smun[nums.size() + 10];
        smun[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i --) {
            smun[i] = min(smun[i + 1], nums[i]);
        }
        int mm = 0;
        for (int i = 0; i < nums.size() - 1; i ++) {
            mm = max(mm, nums[i]);
            if (mm <= smun[i + 1]) return i + 1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,0,3,8,6};
    cout << s.partitionDisjoint(nums) << endl;

}