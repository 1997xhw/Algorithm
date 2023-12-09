//
// Created by 徐浩闻 on 2023/12/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:


    int smallestDivisor(vector<int> &nums, int threshold) {
        sort(nums.begin(), nums.end());
        cout << endl;
        function<bool(int)> check = [&](int mid) -> bool {
            int index = 0;

            while (nums[index] <= mid) index++;
            cout << "mid: " << mid << endl;
            cout << "index: " << index << endl;
            int ans = 0;
            ans += index;
            while (index < nums.size()) ans += (nums[index]%mid==0?nums[index++·]/mid: (nums[index++] / mid) +1);
//            ans += (prefix[nums.size()] - prefix[index]) / mid;
            cout << "ans: " << ans << endl;
            return ans <= threshold;

        };
        int l = 1, r = nums[nums.size() - 1];
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.smallestDivisor(nums, 6);

}