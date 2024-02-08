//
// Created by 徐浩闻 on 2024/2/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        deque<int> q = {0};
        for (int i = 1; i < n; i ++) {
            if (q.front()< i - k) q.pop_front();
            f[i] = f[q.front()]+nums[i];
            while(!q.empty() && f[q.back()] <= f[i]) q.pop_back();
            q.push_back(i);
        }
        return f[n-1];
    }
};

int main() {


}