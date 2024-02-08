//
// Created by 徐浩闻 on 2024/2/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> pos = {1, 0, -1, 0, 1};

    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> vi(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int cnt = 0;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = x + pos[i], ny = y + pos[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (maze[nx][ny] == '+') continue;
                    if ((nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) && maze[nx][ny] == '.') return vi[x][y] + 1;
                    q.push({nx, ny});
                    maze[nx][ny] = '+';
                    vi[nx][ny] = vi[x][y] + 1;
                }
            }
        }
        return -1;
    }
};

int main() {


}