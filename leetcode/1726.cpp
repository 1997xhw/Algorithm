//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); ++j) {
                mp[nums[i] * nums[j]]++;
            }
        }
        for (const auto &item: mp) {
            cnt += item.second * (item.second - 1) / 2;
        }
        return cnt * 8;
    }
};

int main() {


}
