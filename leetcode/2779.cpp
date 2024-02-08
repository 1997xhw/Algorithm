//
// Created by 徐浩闻 on 2024/2/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        int n = nums.size();
//        vector<int> mp(n+1, 0);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i] - k >= 0 ? nums[i] - k : 0]++;
            mp[nums[i] + k + 1]--;
        }
        for (auto &item: mp) cout << item.first << " " << item.second << endl;
        int cnt = 0, mm = 0;
        int ans = 0;
        for (auto &item: mp) {
            cnt += item.second;
            ans = max(ans, cnt);
        }
        return ans;

    }
};

int main() {
    vector<int> nums = {4, 6, 1, 2};
    Solution s;
    cout << s.maximumBeauty(nums, 2);

}