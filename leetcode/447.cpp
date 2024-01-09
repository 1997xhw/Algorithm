//
// Created by 徐浩闻 on 2024/1/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int ans;
        unordered_map<long long, int> mp;
        for (int i = 0; i < points.size(); i++) {
            mp.clear();
            for (int j = 0; j < points.size(); j++) {
                long long tmp =(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
                                     (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                mp[tmp]++;
            }
            for (auto &item: mp) {
                ans += item.second * (item.second - 1);
            }
        }
        return ans;
    }
};

int main() {


}