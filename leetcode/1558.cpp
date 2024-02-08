//
// Created by 徐浩闻 on 2024/1/31.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int ans = 0, cnt = 0;
        for (auto &num: nums) {
            ans += __builtin_popcount(num);
            int tmp = 0;
            while (num) {
                num >>= 1;
                tmp++;
            }
            cnt = max(cnt, tmp - 1);
        }
        ans += cnt;
    }
};

int main() {


}