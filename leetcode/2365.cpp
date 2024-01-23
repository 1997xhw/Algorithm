//
// Created by 徐浩闻 on 2024/1/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int> &tasks, int space) {
        long long day = 0;
        unordered_map<int, long long> mp;
        int i = 0, n = tasks.size();
        while (i < n) {
            if (mp.find(tasks[i]) != mp.end() && mp[tasks[i]] + space >= day)
                day = mp[tasks[i]] + space + 1;
            mp[tasks[i]] = day;
            day++;
            i++;
        }
        return day;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 2, 3, 1};
    Solution s;
    cout << s.taskSchedulerII(nums, 3);

}