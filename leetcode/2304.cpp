//
// Created by 徐浩闻 on 2024/3/14.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        if (grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f));
        for (int i = 0; i < n; i++) dp[m - 1][i] = grid[m - 1][i];
        if (m >= 2) {
            for (int i = m - 2; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        dp[i][j] = min(dp[i][j], grid[i][j]+dp[i + 1][k] + moveCost[grid[i][j]][k]);
                    }
                }
            }
        }
        int res = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[0][i]);
        }
        return res;
    }
};

int main() {


}