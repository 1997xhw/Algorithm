//
// Created by 徐浩闻 on 2023/12/24.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        vector<int> prefix;
        unordered_map<int, int> hs;
        hs[0]++;
        int res = 0, cnt = 0;
        for (auto &n: nums) {
            cnt += n;
            if(hs.find(cnt-goal)!= hs.end()) res+=hs[cnt-goal];
            hs[cnt]++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0, 0};
    Solution s;
    cout << s.numSubarraysWithSum(nums, 0) << endl;

}
