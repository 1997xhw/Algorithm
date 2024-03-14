//
// Created by 徐浩闻 on 2024/3/2.
//
#include "bits/stdc++.h"

using namespace std;


vector<int> dist = {1, 0, 1, -1, 0, -1, -1, 1, 1};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int m = grid.size();
        if (grid[0][0] == 1 || grid[m - 1][m - 1] == 1)
            return -1;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int ans = 0;
        grid[0][0] = 1;
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (tmp.first == m - 1 && tmp.second == m - 1) break;
            for (int i = 0; i < 8; i++) {
                int pos_i = tmp.first + dist[i];
                int pos_j = tmp.second + dist[i + 1];
                if (pos_i < 0 || pos_i >= m || pos_j < 0 || pos_j >= m) continue;
                if (grid[pos_i][pos_j] == 0) {
                    q.push(make_pair(pos_i, pos_j));
                    grid[pos_i][pos_j] = grid[tmp.first][tmp.second] + 1;
                }
            }
        }
        if(grid[m-1][m-1]==0) return -1;
        return grid[m-1][m-1];

    }
};

int main() {


}