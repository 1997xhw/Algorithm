//
// Created by 徐浩闻 on 2024/1/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; --i) {
            while(!st.empty() && st.top() < heights[i]) {
                st.pop();
                ans[i]++;
            }
            if(!st.empty()) ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};

int main() {


}