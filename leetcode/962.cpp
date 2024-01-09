//
// Created by 徐浩闻 on 2024/1/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int> &nums) {
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[st.top()]) st.push(i);
        }
        int j = nums.size() - 1, res = -1;
        while (!st.empty() && st.top() <= j) {
            if (nums[st.top()] <= nums[j]) {
                res = max(res, j - st.top());

                st.pop();
            } else j--;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    Solution s;
    s.maxWidthRamp(nums);

}