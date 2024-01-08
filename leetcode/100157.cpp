//
// Created by 徐浩闻 on 2024/1/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int missingInteger(vector<int> &nums) {
        int i = 0, j = 0, n = nums.size();
        unordered_set<int> ss(nums.begin(), nums.end());
        int mm = -1;
        int tmp = nums[0];
        for (j = 1; j < n && nums[j] - nums[j - 1] == 1; j++) {
            tmp += nums[j];
        }
        while (ss.count(tmp) == 1) {
            tmp++;
        }
        return tmp;
    }
};
int main() {


}