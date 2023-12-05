//
// Created by 徐浩闻 on 2023/12/1.
//
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j++ - i);
            } else {
                i ++;
            }
        }
        return ans;
    }
};

int main() {


}