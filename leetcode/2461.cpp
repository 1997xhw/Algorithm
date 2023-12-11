//
// Created by 徐浩闻 on 2023/12/11.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> np;
        long long i = 0, j = 0, ans = 0, sum = 0;
        while (i < nums.size() && j < nums.size()) {
            if (np.find(nums[j]) == np.end() || np[nums[j]] == 0) np[nums[j]] = 1;
            else np[nums[j]]++;
            sum += nums[j];
            while (np[nums[j]] > 1 || j - i + 1 > k) {
                np[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            if (j - i + 1 == k) {
                ans = max(ans, sum);
//                cout << i << " " << j << endl;
            }
            j++;
        }
        return ans;

    }
};

int main() {
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
//    vector<int> nums = {4,4,4};
    Solution s;
    cout << s.maximumSubarraySum(nums, 3);

}