//
// Created by 徐浩闻 on 2023/11/9.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
    const int dirs[4][2] = {{-1, 0},
                            {1,  0},
                            {0,  -1},
                            {0,  1}};


    bool check(vector<vector<int>> &grid, int t) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> on_fired(m, vector<int>(n));
        vector<pair<int, int>> f;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    on_fired[i][j] = true;
                    f.emplace_back(i, j);
                }
            }
        }
        auto spread_fire = [&]() {
            vector<pair<int, int>> nf;
            for (auto &[i, j]: f) {
                for (auto &[dx, dy]: dirs) {
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < m && 0 <= y && y < n && !on_fired[x][y] && grid[x][y] == 0) {
                        on_fired[x][y] = true;
                        nf.emplace_back(x, y);
                    }
                }
            }
            f = move(nf);
        };
        while (t-- && !f.empty()) {
            spread_fire();
        }
        if (on_fired[0][0]) {
            return false;//起点着火
        }

        vector<vector<int>> vis(m, vector<int>(n));
        vis[0][0] = true;
        vector<pair<int, int>> q{{0, 0}};
        while (!q.empty()) {
            vector<pair<int, int>> nq;
            for (auto &[i, j]: q) {
                if (on_fired[i][j]) continue;
                for (auto &[dx, dy]: dirs) {
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < m && 0 <= y && y < n && !on_fired[x][y] && !vis[x][y] && grid[x][y] == 0) {
                        if (x == m - 1 && y == n - 1) {
                            return true;//能够抵达
                        }
                        vis[x][y] = true;
                        nq.emplace_back(x, y);
                    }
                }
            }
            q = move(nq);
            spread_fire();
        }
        return false;

    }

public:
    int maximumMinutes(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int ll = -1, rr = m * n + 1;
        while (ll + 1 < rr) {
            int mid = (ll + rr) / 2;
            (check(grid, mid) ? ll : rr) = mid;
        }
        return ll < m * n ? ll : 1000000000;
    }
};

int main() {

    Solution s;
    vector<vector<int>> grid{{0, 2, 0, 0, 0, 0, 0},
                             {0, 0, 0, 2, 2, 1, 0},
                             {0, 2, 0, 0, 1, 2, 0},
                             {0, 0, 2, 2, 2, 0, 2},
                             {0, 0, 0, 0, 0, 0, 0}};
    cout << s.maximumMinutes(grid);
}