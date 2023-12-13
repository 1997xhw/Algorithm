//
// Created by 徐浩闻 on 2023/12/12.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int> &nums) {
        int s[2]{}, n = nums.size();
        for (int i = 0; i < n; i++) {
            int left = i ? nums[i - 1] : INT_MAX;
            int right = i + 1 < n ? nums[i + 1] : INT_MAX;
            s[i % 2] += max(nums[i] - min(left, right) + 1, 0);
        }
        return min(s[0], s[1]);
    }
};

int main() {


}