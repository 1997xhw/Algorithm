//
// Created by 徐浩闻 on 2023/11/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDeletion(vector<int> &nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i ++) {
            int ii = i - cnt;
            if ((ii) % 2 == 0 && nums[i] == nums[i + 1]) {
                cnt ++ ;
            }
        }
        if ((nums.size() - cnt) % 2 == 1) cnt ++;
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2,2,3,3};
    cout << s.minDeletion(nums) << endl;

}