//
// Created by 徐浩闻 on 2023/12/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        if (obstacleGrid[0][0]==1) return 0;
        for(int i = 0; i <m; i++) {
            for(int j = 0; j < n; j++) {// 跳过起点
                if (i == 0 && j == 0) continue;// 检查当前位置是否有障碍物
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j]; // 从上方来
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1]; // 从左侧来
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> obs ={{0,0,0}, {0,1,0}, {0,0,0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(obs);

}