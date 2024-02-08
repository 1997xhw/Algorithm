//
// Created by 徐浩闻 on 2024/2/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        vector<int> mp(32, 0);
        for (auto &item: candidates) {
            int cnt = 0;
            while (item) {
                if ((item & 1) == 1) mp[cnt]++;
                cnt++;
                item >>= 1;
            }
        }
        return *max_element(mp.begin(), mp.end());
    }
};

int main() {


}