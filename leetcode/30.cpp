//
// Created by 徐浩闻 on 2024/2/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int magicTower(vector<int> &nums) {
        int n = nums.size();
        long long cnt = 1;
        stack<int> st;
        queue<int> right;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                cnt += nums[i];
                continue;
            } else if (nums[i] + cnt <= 0) {
                if (!heap.empty() && heap.top() < nums[i]) {
                    right.push(heap.top());
                    cnt -= heap.top();
                    heap.pop();
                    heap.push(nums[i]);
                    cnt += nums[i];
                } else {
                    right.push(nums[i]);
//                    cout << nums[i] << endl;
                }
            } else {
                cnt += nums[i];
                heap.push(nums[i]);
            }
        }
        int ans = right.size();
        while (!right.empty()) {
            cnt += right.front();
            right.pop();
        }
        return cnt < 0 ? -1 : ans;

    }
};

int main() {
    vector<int> nums = {5,-4,1,-2,-2,-2,4};
    Solution s;
    cout << s.magicTower(nums);

}