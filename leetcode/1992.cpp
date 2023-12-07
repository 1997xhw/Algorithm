//
// Created by 徐浩闻 on 2023/12/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        int rows = land.size();
        int cols = (rows > 0) ? land[0].size() : 0;

        // 向每行的开始和结束添加 0
        for (auto &row: land) {
            row.emplace(row.begin(), 0);    // 在行首添加 0
            row.emplace_back(0);              // 在行尾添加 0
        }

        // 创建由 0 组成的新行
        std::vector<int> zeroRow(cols + 2, 0);

        // 在 land 的顶部和底部添加新行
        land.emplace(land.begin(), zeroRow); // 在顶部添加
        land.emplace_back(zeroRow);             // 在底部添加
        vector<vector<int>> res;
        for (int i = 0; i < rows + 2; ++i) {
            for (int j = 0; j < cols + 2; ++j) {
                if (land[i][j] == 1 && land[i - 1][j] == 0 && land[i][j - 1] == 0) {
                    int x = i, y = j;
                    while (land[x + 1][j] != 0) x++;
                    while (land[x][y + 1] != 0) y++;
                    res.push_back({i - 1, j - 1, x - 1, y - 1});
                }
            }
        }
        return res;
    }
};

int main() {


}