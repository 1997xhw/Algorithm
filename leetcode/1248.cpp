//
// Created by 徐浩闻 on 2024/1/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int ans = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i]%2==1) {
                cnt++;
            }
            if (mp.find(cnt-k)!=mp.end()) {
                ans+=mp[cnt-k];
            }
            mp[cnt]++;
        }
        return ans;
    }
};

int main() {


}