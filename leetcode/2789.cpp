//
// Created by 徐浩闻 on 2024/3/14.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int> &nums) {
        stack<long long> st;
        long long mm = LONG_LONG_MIN;
        int len = nums.size();
        for (int i = len - 1; i >= 0; i--) {
            if (st.empty() || st.top() < nums[i]) st.push(nums[i]);
            else {
                st.top() += nums[i];

            }
            mm = max(st.top(), mm);
        }
        return mm;
    }
};

int main() {


}