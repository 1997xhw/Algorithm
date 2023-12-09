//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int left = 0, count = 0;
        unordered_map<int, int> freq;
        int me = *max_element(nums.begin(), nums.end());
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == me) {
                count++;
            }
            freq[nums[right]]++;
            while (count >= k) {
                ans += nums.size() - right;
                freq[nums[left]]--;
                if (nums[left] == me) {
                    count--;
                }
                left++;
            }
        }
        return ans;
    }
};

int main() {
vector<int> nums = {1,3,2,3,3};
int k = 2;
Solution s;
cout << s.countSubarrays(nums, k);

}