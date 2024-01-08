//
// Created by 徐浩闻 on 2024/1/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findBestValue(vector<int> &arr, int target) {
        int n = arr.size();
        function<int(int)> judge = [&](int val) -> int {
            int total = 0;
            for (auto &i: arr) {
                total += min(i, val);
            }
            return total;
        };
        int left = 0, right = *max_element(arr.begin(), arr.end());
        while (left < right) {
            int mid = (left + right) >> 1;
            if (judge(mid) < target) left = mid + 1;
            else right = mid;
        }
        int x = judge(left), y = judge(left - 1);
        int ans = 0;
        ans = x - target >= target-y ? left - 1 : left;
        return ans;
    }
};

int main() {


}