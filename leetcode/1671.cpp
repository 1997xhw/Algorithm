//
// Created by 徐浩闻 on 2023/12/22.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void Lis(vector<int> &f, vector<int> &g, vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int l = 0, r = g.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (g[mid] < nums[i]) l = mid + 1;
                else r = mid;
            }
            if (l == g.size()) {
                g.emplace_back(nums[i]);
                f[i] = g.size();
            } else {
                g[l] = nums[i];
                f[i] = l + 1;
            }
        }
    }

    int minimumMountainRemovals(vector<int> &nums) {
        int len = nums.size();
        vector<int> g;
        vector<int> left(len, 0), right(len, 0);
        Lis(left, g, nums);
        for (auto &item: left) {
            cout << item << " ";
        }
        cout << endl;
        g.clear();
        reverse(nums.begin(), nums.end());
        Lis(right, g, nums);
        reverse(right.begin(), right.end());
        for (auto &item: right) {
            cout << item << " ";
        }
        cout << endl;
        int mm = 0;
        for (int i = 1; i < len-1; i++) {
            if(left[i]==1 || right[i]==1) continue;
            mm = max(mm, left[i] + right[i] - 1);
        }


        return len - mm;
    }
};

int main() {
    vector<int> nums = {100,92,89,77,74,66,64,66,64};
    Solution s;
    cout << s.minimumMountainRemovals(nums);
}