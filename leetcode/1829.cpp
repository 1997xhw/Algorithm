//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        vector<int> ans;
        int num = nums[0], bit = (1 << maximumBit) - 1;
        ans.push_back(num ^ bit);
        for(int i = 1; i < nums.size(); i ++) {
            num ^= nums[i];
            ans.push_back(num ^ bit);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {


}