//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        int city[n][n];
        int cnt[n];
        memset(city, 0, sizeof city);
        memset(cnt, 0, sizeof cnt);
        for (const auto &road: roads) {
            int a = road[0], b = road[1];
            city[a][b] = city[b][a] = 1;
            ++cnt[a];
            ++cnt[b];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, cnt[i] + cnt[j] - city[i][j]);
            }
        }
        return ans;

    }
};

int main() {


}