//
// Created by 徐浩闻 on 2024/2/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix) {
        vector<int> lis;
        long long cnt = 0;
        int cnt2 = 0;
        int minn = INT_MAX;
        for (auto &nums: matrix) {
            for (auto &num: nums) {
                cnt+=abs(num);
                minn = min(minn, num*-1);
                if(num<0) cnt2++;
            }
        }
        if (cnt2 % 2 == 0 ) return cnt;
        else {
            return cnt - minn*2;
        }

    }
};

int main() {


}
