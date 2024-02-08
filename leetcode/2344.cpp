//
// Created by 徐浩闻 on 2024/2/2.
//
#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

class Solution {
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide) {
        int g = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++) g = gcd(g, numsDivide[i]);
        cout << "g: " << g << endl;
        sort(nums.begin(), nums.end());
        if (nums[0] > g) return -1;
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < g) l = mid + 1;
            else r = mid;
        }
        cout << l << endl;
        for (int i = 0; i < l; i++) {
            if (g % nums[i] == 0) return i;
        }
        if (nums[l] == g)
            return l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {14};
    vector<int> numsDivide = {86};
    cout << s.minOperations(nums, numsDivide);

}