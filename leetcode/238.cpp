//
// Created by 徐浩闻 on 2024/2/1.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> l, r(n+1, 1);
        l.emplace_back(1);
        for (int i = 1; i <= n; i++)
            l.emplace_back(l[i - 1] * nums[i - 1]);
        for (int i = n-1; i >= 1; i--)
            r[i] = r[i + 1] * nums[i];
        vector<int> ans;
        for (int i = 0; i < n; i ++) {
            ans.emplace_back(l[i]*r[i+1]);
        }
        return ans;
    }
};

int main() {


}