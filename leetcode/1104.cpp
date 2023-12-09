//
// Created by 徐浩闻 on 2023/12/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        ans.emplace(ans.begin(), label);
        while (label != 1) {
            int floor = static_cast<int>(log2(label)) + 1;
            cout << "bottom_floor: " << floor << endl;
            int pre_begin = 1 << floor - 2, pre_end = (1 << (floor - 1)) - 1;
            cout << "pre_begin: " << pre_begin << " pre_end: " << pre_end << endl;
            int pre = pre_begin + pre_end - (label >> 1);
            cout << "pre: " << pre << endl;
            ans.emplace(ans.begin(), pre);
            label = pre;
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.pathInZigZagTree(14);

}