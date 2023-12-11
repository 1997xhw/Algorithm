//
// Created by 徐浩闻 on 2023/12/11.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int p[10005];
    int row, col;

    void uni(int a, int b) {
        p[find(a)] = p[find(b)];
    }

    bool query(int a, int b) {
        return p[find(a)] == p[find(b)];
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int minimumEffortPath(vector<vector<int>> &heights) {
        row = heights.size();
        col = heights[0].size();

        for (int i = 0; i < row * col; i++) p[i] = i;
        vector<vector<int>> edges;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int idx = i * col + j;
                if (i + 1 < row) {
                    int a = idx, b = idx + col;
                    int w = abs(heights[i][j] - heights[i + 1][j]);
                    vector<int> edge = {a, b, w};
                    edges.emplace_back(edge);
                }
                if (j + 1 < col) {
                    int a = idx, b = idx + 1;
                    int w = abs(heights[i][j] - heights[i][j + 1]);
                    vector<int> edge = {a, b, w};
                    edges.emplace_back(edge);
                }

            }
        }
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[2] < b[2];
        });

        int start = 0, end = row * col - 1;
        for (auto &edge: edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            uni(a, b);
            if(query(start, end)) return w;
        }
        return 0;


    }
};

int main() {
    vector<vector<int>> map = {{1, 2, 2},
                               {3, 8, 2},
                               {5, 3, 5}};
    Solution s;
    cout << s.minimumEffortPath(map) << endl;

}