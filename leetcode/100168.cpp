//
// Created by 徐浩闻 on 2024/1/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        for (auto &item: nums) {
            k ^= item;
        }
        return __builtin_popcount(k);
    }
};

int main() {


}