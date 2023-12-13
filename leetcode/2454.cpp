//
// Created by 徐浩闻 on 2023/12/12.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> st;
        vector<int> temp;
        vector<int> ans(n, -1);
        for (int i = 0; i < nums.size(); i++) {
            while (!temp.empty() && nums[temp.back()] < nums[i]) {
                ans[temp.back()] = nums[i];
                temp.pop_back();
            }
            int j = st.size() - 1;
            while (j >= 0 && nums[st[j]] < nums[i]) j--;
            temp.insert(temp.end(), st.begin() + (j + 1), st.end());
            st.resize(j+1);
            st.emplace_back(i);
        }
        return ans;
    }
};

int main() {


}