//
// Created by 徐浩闻 on 2023/12/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isRev(int x) {
        string s;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    long long countVal(vector<int> &nums, int mid) {
        int n = nums.size();
        long long res = 0;
        for (int j = 0; j < n; j++) {
            res += abs(nums[j] - mid);
        }
        return res;
    }

    long long minimumCost(vector<int> &nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int median = nums[n / 2];
        cout << median << endl;
        int l = median;
        while (l > 0 and !isRev(l))l--;
        int r = median;
        while (r <= 1e9 and !isRev(r)) r++;
        long long ans = 0;
        ans = min(countVal(nums, l), countVal(nums, r));
        return ans;
    }
};

int main() {
    vector<int> nums = {10, 12, 13, 14, 15};
    Solution s;
    cout << s.minimumCost(nums);

}