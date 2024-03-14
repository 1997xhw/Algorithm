//
// Created by 徐浩闻 on 2024/3/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        vector<long long> dist(n, LONG_LONG_MAX / 2);
        vector<long long> dp(n, 0);
        vector<bool> vis(n, true);
        vector<vector<int>> mp(n + 1, vector<int>(n + 1, 0));
        for (auto &item: roads) {
            mp[item[0]][item[1]] = item[2];
            mp[item[1]][item[0]] = item[2];
        }
        dp[0] = 1;
        dist[0] = 0;
        vis[0] = false;
        while (true) {
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (vis[i] && (x < 0 || dist[i] < dist[x])) {
                    x = i;
                }
            }
            if (x == n - 1) {
                return dp[n - 1];
            }
            vis[x] = false;
            for (int y = 0; y < n; y++) {
                long long new_dist = dist[x] + mp[x][y];
                if (new_dist < dist[y]) {
                    dist[y] = new_dist;
                    dp[y] = dp[x];
                } else if (new_dist == dist[y]) {
                    dp[y] = (dp[y] + dp[x]) % 1000000007;
                }
            }
        }


    }
};

int main() {

}