//
// Created by 徐浩闻 on 2023/12/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> diff(n + 2, vector<int>(n + 2));
        for (auto &q: queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            ++diff[r1 + 1][c1 + 1];
            --diff[r1 + 1][c2 + 2];
            --diff[r2 + 2][c1 + 1];
            ++diff[r2 + 2][c2 + 2];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; j++) {
                diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
            }
        }
        diff.pop_back(), diff.erase(diff.begin());
        for (auto &item: diff)
            item.pop_back(), item.erase(item.begin());
        return diff;
    }
};

int main() {


}