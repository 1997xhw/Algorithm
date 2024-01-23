//
// Created by 徐浩闻 on 2024/1/22.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int count = 0;
    void DFS(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 0) return;
        grid[x][y] = 0;
        ++count;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if (newx < 0 || newx >= grid.size() || newy < 0 || newy >= grid[0].size()) continue;
            DFS(grid, newx, newy);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1) DFS(grid, i, 0);
            if (grid[i][m - 1] == 1) DFS(grid, i, m - 1);
        }
        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1) DFS(grid, 0, i);
            if (grid[n - 1][i] == 1) DFS(grid, n - 1, i);
        }
        count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
};

int main() {


}