//
// Created by 徐浩闻 on 2024/3/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> d(nums.size(), 0);
        d[0] = nums[0] - 1;
        nums.insert(nums.begin(), 1, 0);
        int cnt = 1;
        long long ans = 0;
        for (int i = 1; i < nums.size() && k > 0; i++) {
            int gap = nums[i] - nums[i - 1] - 1;
            if(gap <= 0) continue;
            if (gap < k) {
                ans+=(long long)(nums[i-1]+1+nums[i-1]+gap)*gap/2;
                k-=gap;
            }else {
                ans += (long long)(nums[i - 1] + 1 + nums[i - 1] + k) * k / 2;
                k = 0;
                break;
            }
        }
        if (k > 0) {
            int last = nums.back();
            ans+=(long long)(last+1+last+k)*k/2;
        }
        return ans;

    }
};

int main() {
vector<int> nums = {1,4,25,10,25};
Solution s;
cout << s.minimalKSum(nums, 2);

}