//
// Created by 徐浩闻 on 2024/1/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    unordered_map<long long, int> mp;

    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int, int>> q;
        unordered_set<int> seen;
        q.push({x, 0});
        while(!q.empty()) {
            auto [curr, step] = q.front();
            q.pop();

        }

    }

    int minOperations(vector<int> &nums, int k) {
        int xorSum = 0;
        for (int num: nums) {
            xorSum ^= num;
        }
        if (xorSum == k) {
            return 0;
        }

        int xorDiff = xorSum ^ k;
        int flips = 0;
        while (xorDiff > 0) {
            flips += xorDiff & 1;
            xorDiff >>= 1;
        }

        return flips;
    }

    int missingInteger(vector<int> &nums) {
        int i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mp;
        int mm = -1;
        int tmp = nums[0];
        mp[nums[0]]++;
        for (j = 1; j < n && nums[j]-nums[j-1]==1; j++) {
            tmp += nums[j];
            mp[nums[j]]++;
        }
        while (find(nums.begin(), nums.end(), tmp)!=nums.end()) {
            tmp++;
        }
        return tmp;
    }

};

int main() {
    vector<int> nums = {14,9,6,9,7,9,10,4,9,9,4,4};
    Solution s;
    cout << s.missingInteger(nums);

}