//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int i = 0, j = 0;
        int maps[10005] = {0};
        int temp_sum = 0, ans = 0;
        while(j < nums.size()) {
           while(maps[nums[j]]>0) {
               maps[nums[i]]--;
               temp_sum-=nums[i];
               i++;
           }
           maps[nums[j]]++;
           temp_sum += nums[j];
           ans = max(ans, temp_sum);
           j++;
        }
        return ans;
    }
};

int main() {
Solution s;
vector<int> nums = {4,2,4,5,6};
cout << s.maximumUniqueSubarray(nums) << endl;

}