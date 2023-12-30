//
// Created by 徐浩闻 on 2023/12/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ct(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        unordered_map<long long, int> hash;
        for (int i = 0; i < nums2.size() - 1; i++) {
            for(int j = i+1; j < nums2.size(); j++) {
                hash[(long long)nums2[i]*nums2[j]]++;
            }
        }
        for (auto &i: nums1) {
            if(hash.find((long long)i*i)!=hash.end()) res+=hash[(long long)i*i];
        }
        return res;
    }

    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        return ct(nums1, nums2) + ct(nums2, nums1);
    }
};

int main() {
    vector<int> nums1 = {43024,99908};
    vector<int> nums2 = {1864};
    Solution s;
    cout << s.numTriplets(nums1, nums2) << endl;

}