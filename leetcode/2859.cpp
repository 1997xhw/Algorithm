//
// Created by 徐浩闻 on 2024/1/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int tmp = i, kk = 0;
            while (tmp) {
                if ((tmp & 1) == 1) kk++;
                tmp >>= 1;
            }
            if (kk == k) ans += nums[i];
        }
        return ans;
    }
};

int main() {


}