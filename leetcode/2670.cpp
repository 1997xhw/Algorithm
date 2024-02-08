//
// Created by 徐浩闻 on 2024/1/31.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int> &nums) {
        unordered_map<int, int> left, right;
        int cnt_l = 1, cnt_r = 0, n = nums.size();
        vector<int> ans;
        left[nums[0]]++;
        for (int i = nums.size() - 1; i > 0; i--) {
            right[nums[i]]++;
            if (right[nums[i]] == 1) cnt_r++;
        }
        for (int i = 0; i < n; i++) {
            ans.emplace_back(cnt_l - cnt_r);
            if (i + 1 < n) {
                right[nums[i + 1]]--;
                left[nums[i + 1]]++;
                if (left[nums[i + 1]] == 1) cnt_l++;
                if (right[nums[i + 1]] == 0) cnt_r--;
            }

        }
        return ans;

    }
};

int main() {


}