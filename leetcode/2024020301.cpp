//
// Created by 徐浩闻 on 2024/2/3.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string triangleType(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b <= c) return "none";
        if (a == b && b == c) return "equilateral";
        else if ((a == b && b != c) || (b == c && a != b)) return "isosceles";
        else return "scalene";
    }

    int numberOfPairs(vector<vector<int>> &points) {
        int count = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) {
                    bool isValid = true;
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            if (points[k][0] >= points[i][0] && points[k][0] <= points[j][0] &&
                                points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
                                isValid = false;
                                break;
                            }
                        }
                    }
                    if (isValid) count++;
                }
            }
        }
        return count;
    }

//    long long maximumSubarraySum(vector<int> &nums, int k) {
//        int n = nums.size();
//        vector<long long> prefix(n + 1, 0);
//        for (int i = 1; i <= n; i++) {
//            prefix[i] = prefix[i - 1] + nums[i - 1];
//        }
//        long long ans = INT_MIN;
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (abs(nums[i] - nums[j]) == k) {
//                    ans = max(ans, prefix[j + 1] - prefix[i]);
//                }
//            }
//        }
//        return ans;
//    }
    long long maximumSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        long long ans = LONG_MIN, cnt = 0;
        unordered_map<int, long long> mp;
        for (int i = 0; i < n; i++) {
            auto it = mp.find(nums[i]);
            if (it == mp.end()) mp[nums[i]] = cnt;
            else if (cnt < it->second) it->second = cnt;
            cnt += nums[i];
            it = mp.find(nums[i] + k);
            if (it != mp.end()) ans = max(ans, cnt - it->second);
            it = mp.find(nums[i] - k);
            if (it != mp.end()) ans = max(ans, cnt - it->second);
        }
        if (ans == LONG_MIN) ans = 0;
        return ans;
    }

};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    int k1 = 1;
    cout << "Example 1: " << s.maximumSubarraySum(nums1, k1) << endl;

    vector<int> nums2 = {-1, 3, 2, 4, 5};
    int k2 = 3;
    cout << "Example 2: " << s.maximumSubarraySum(nums2, k2) << endl;

    vector<int> nums3 = {-1, -2, -3, -4};
    int k3 = 2;
    cout << "Example 3: " << s.maximumSubarraySum(nums3, k3) << endl;
}