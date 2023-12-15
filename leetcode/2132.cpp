//
// Created by 徐浩闻 on 2023/12/14.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> vis, sum;

    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        vis = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
        sum = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
        //二维前缀和
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        //二维差分 如果有空就将邮票塞进去
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = i + stampHeight - 1, y = j + stampWidth - 1;
                if (x > n || y > m) continue;
                int t = sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
                if (!t) {
                    vis[i][j]++;
                    vis[i][y + 1]--;
                    vis[x + 1][j]--;
                    vis[x + 1][y + 1]++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                vis[i][j] += vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!grid[i - 1][j - 1] && !vis[i][j]) return false;
            }
        }
        return true;

    }
};

int main() {


}
