//
// Created by 徐浩闻 on 2024/1/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int K) {
        int n = nums1.size();
        long long neg = 0, pos = 0;
        for (int i = 0; i < n; i++) {
            long long det = nums1[i] - nums2[i];
            if (K == 0) {
                if (det != 0) return -1;
            } else {
                if (det % K) return -1;
                if (det < 0) neg -= det / K;
                else pos += det / K;
            }
        }
        if (neg != pos) return -1;
        return pos;
    }
};

int main() {


}