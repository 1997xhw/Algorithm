//
// Created by 徐浩闻 on 2023/12/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int> &nums) {
        int sum = 0, len = nums.size();
        vector<int> sums;
        if (len == 1) return 0;
        sums.push_back(0);
        for (int i = 1; i <= len; ++i) {
            sums.push_back(sums[i - 1] + nums[i - 1]);
        }

        for (int i = 1; i <= len; i++) {
            if (sums[i-1] == sums[len] - sums[i]) {
                return i-1;
            }
        }
        return -1;

    }
};

int main() {


}