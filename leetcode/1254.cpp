//
// Created by 徐浩闻 on 2024/3/16.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
    void dfs(vector<vector<int>> &grid, bool &closed, int x, int y) {
        if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[x].size() - 1) {
            if (grid[x][y] == 0) closed = false; // 到达边界
            return;
        }
        if (grid[x][y]) return;
        grid[x][y] = 1; // 标记 (x,y) 被访问，避免重复访问
        dfs(grid, closed, x - 1, y);
        dfs(grid, closed, x + 1, y);
        dfs(grid, closed, x, y - 1);
        dfs(grid, closed, x, y + 1);
    }

public:
    int closedIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        if (m < 3 || n < 3) return 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) { // 从没有访问过的 0 出发
                    bool closed = true;
                    dfs(grid, closed, i, j);
                    ans += closed;
                }
            }
        }
        return ans;
    }
};



int main() {


}