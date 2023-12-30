//
// Created by 徐浩闻 on 2023/12/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int> &nums) {
        int i = 0, n = nums.size();
        const int MOD = 1e9 + 7;
        while (i < n && nums[i] == 0) i++;
        if (i == n) return 0;
        int res = 1;
        while (i < n) {
            i++;
            int tmp = 0;
            while (i < n && nums[i] == 0) {
                tmp++;
                i++;
            }
//            cout << "i: " << i  << " " << tmp << endl;
            if (i < n && nums[i] == 1)
                res = (tmp + 1) * res % MOD;
        }
        return res;
    }
};

int main() {
 vector<int> nums = {0,1,0,0,1,1,0,0,1};
 Solution solution;
 cout << solution.numberOfGoodSubarraySplits(nums);

}