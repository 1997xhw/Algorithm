//
// Created by 徐浩闻 on 2023/12/18.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};

    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        vector<pair<int, int>> que;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ii = 0, now_color = grid[row][col];
        que.emplace_back(row, col);
        while (ii < que.size()) {
            for (int i = 0; i < 4; i++) {
                int x = que[ii].first + dir[i], y = que[ii].second + dir[i + 1];
                if (x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]) {
                    if (grid[x][y] == now_color) {
                        que.emplace_back(x, y);
                    }
                }
            }
            visited[que[ii].first][que[ii].second] = true;
            ii++;
        }
        vector<pair<int, int>> res;
        for (auto &item: que) {
//            cout << item.first << " " << item.second << endl;
            for (int i = 0; i < 4; i++) {
                int x = item.first + dir[i], y = item.second + dir[i + 1];
                if (x < 0 || x > n - 1 || y < 0 || y > m - 1 ||
                    (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != now_color)) {
//                    cout << item.first << " " << item.second << endl;
                    res.emplace_back(item);
                }

            }
        }
        for (auto &item: res) grid[item.first][item.second] = color;
        return grid;
    }
};

int main() {
    vector<vector<int>> grid = {{1,1,1},
                                {1,1,1},
                                {1,1,1}};
    Solution s;
    grid = s.colorBorder(grid, 1,1,2);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
//            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}