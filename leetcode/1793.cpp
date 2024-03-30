//
// Created by 徐浩闻 on 2024/3/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }


        vector<int> right(n , n);
        st = stack<int>();
        for (int i = n-1; i >=0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i ++) {
            int a = nums[i];
            if (left[i] < k && k < right[i]){
                ans = max(ans, a*(right[i]-left[i]-1));
            }

        }
        return ans;

    }
};

int main() {


}