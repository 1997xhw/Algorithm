//
// Created by 徐浩闻 on 2023/12/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (dp[i] == 1) {
                int tmp = 1;
                while (tmp <= nums[i] && (tmp + i) < nums.size()) {
                    dp[tmp + i] = 1;
                    tmp++;
                }
            }
        }
        return dp[n - 1] == 1 ? true : false;
    }
};

int main() {


}