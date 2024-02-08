//
// Created by 徐浩闻 on 2024/1/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int> &nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].emplace_back(i);
        }
        int ans = INT_MAX;
        for (auto &[_, idx]: mp) {
            int n = idx.size();
            int cnt = idx[0] + nums.size() - idx[n - 1];
            for (int i = 1; i < n; i++) {
                cnt = max(cnt, idx[i] - idx[i - 1]);
            }
            ans = min(ans, cnt / 2);
        }
        return ans;
    }
};

int main() {


}