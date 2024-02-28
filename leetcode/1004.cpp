//
// Created by 徐浩闻 on 2024/2/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int res = 0;
        int cnt = 0;
        while (j < n) {
            if (nums[j] == 0) cnt++;
            while (i < n && cnt > k) {
                if (nums[i] == 0) cnt--;
                i++;
            }
            res = max(res, j - i +1);
            j++;
        }
        return res;
    }
};

int main() {


}