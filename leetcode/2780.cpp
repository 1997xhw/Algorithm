//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int> &nums) {
        pair<int, int> max_num = {0, 0};
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
            if (max_num.second < freq[nums[i]]) {
                max_num.first = nums[i];
                max_num.second = freq[nums[i]];
            }
        }
        vector<int> nnums;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_num.first) {
                cnt++;
            }
            nnums.emplace_back(cnt);
            if ((i + 1) < 2 * nnums[i] && (nums.size() - i - 1) < (2 * (max_num.second - nnums[i]))) return i;
        }

//        cnt = 0;
//        for (int i = 0; i < nums.size() - 1; i++) {
//            if ((i + 1) < 2 * nnums[i] && (nums.size() - i - 1) < (2 * (max_num.second - nnums[i]))) return i;
//        }
        return -1;
    }
};

int main() {
    vector<int> nums = {2,1,3,1,1,1,7,1,2,1};
    Solution s;
    cout << s.minimumIndex(nums);

}