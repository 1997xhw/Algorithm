//
// Created by 徐浩闻 on 2024/1/7.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        int common = 0;//共有部分
        for (auto x : set1) common+=set2.count(x);

        int d = max(int(set1.size())-n/2, 0) + max(int(set2.size())-n/2, 0);
        int len = set1.size() + set2.size();
        return len - max(d, common);
    }
};
int main() {

}