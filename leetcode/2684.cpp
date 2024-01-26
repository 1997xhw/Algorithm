//
// Created by 徐浩闻 on 2024/1/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<int>> mp(m, vector<int>(n, 0));
        for (int j = n - 2; j >= 0; j--) {
            int cur = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] < grid[i][j + 1] && mp[i][j] <= mp[i][j + 1]) mp[i][j] = mp[i][j + 1] + 1;
                if (i > 0 && grid[i][j] < grid[i - 1][j + 1] && mp[i][j] <= mp[i - 1][j + 1])
                    mp[i][j] = mp[i - 1][j + 1] + 1;
                if (i + 1 < m && grid[i][j] < grid[i + 1][j + 1] && mp[i][j] <= mp[i + 1][j + 1])
                    mp[i][j] = mp[i + 1][j + 1] + 1;
                cur = max(cur, mp[i][j]);
            }
            ans =max(ans, cur);
        }
        ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, mp[i][0]);
        }
        return ans;
    }
};

int main() {


}