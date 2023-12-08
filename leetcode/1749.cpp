//
// Created by 徐浩闻 on 2023/12/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {

        vector<int> numms;
        numms.emplace_back(0);
        for (int i = 0; i < nums.size(); i++) {
            numms.emplace_back(numms[i] + nums[i]);
        }
        pair<int, int> min = {numms[0], 0};
        pair<int, int> max = {numms[0], 0};
        for (int i = 1; i < numms.size(); i++) {
            if (numms[i] < min.first) min = {numms[i], i};
            if(numms[i] > max.first) max = {numms[i], i};
        }
        if (max.second > min.second) {
            return abs((int)(numms[max.second] - numms[min.second]));
        }else {
            return abs(numms[min.second] - numms[max.second]);
        }

    }
};

int main() {
    vector<int> num = {2,-5,1,-4,3,-2};
//    vector<int> num = {1,-3,2,3,-4};
    Solution s;
    cout << s.maxAbsoluteSum(num);

}
// 0 1 -2 0 3 -1
// 2 -3 -2 -6 -3 -5