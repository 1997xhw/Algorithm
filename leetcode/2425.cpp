//
// Created by 徐浩闻 on 2024/1/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        if (n%2==1){
            for (auto &item: nums2) ans^=item;
        }
        if(m%2==1)
            for (auto &item: nums1) ans^=item;
        return ans;
    }
};

int main() {


}
