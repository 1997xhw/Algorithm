//
// Created by 徐浩闻 on 2023/12/13.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums) {
        int n = nums.size();
        int state = 1 << n;//假设当前子集状态为 state，
        // state为一个仅考虑低 n 位的二进制数
        // 当第 kkk 位为 111，代表 nums[k]参与到当前的按位或运算
        // 当第 k 位为 0，代表 nums[i] 不参与到当前的按位或运算。
        int max = 0, ans = 0;
        for (int i = 0; i < state; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) cur |= nums[i];
            }
            if (cur > max) {
                max = cur;
                ans = 1;
            } else if (cur == max) ans++;
        }

        return ans;

    }
};

int main() {


}