//
// Created by 徐浩闻 on 2023/12/14.
//
#include "bits/stdc++.h"

using namespace std;
//1 3 5 2 1 3 1
//1 1 1 2 3 3 5
class Solution {
public:

    int maximizeGreatness(vector<int> &nums) {
        vector<int> sn = nums;
        sort(sn.begin(), sn.end());
        int i =0;
        for (auto &item: sn) {
            if(item > sn[i]) {
                i++;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums = {1,3,5,2,1,3,1};
    Solution s;
    s.maximizeGreatness(nums);

}
