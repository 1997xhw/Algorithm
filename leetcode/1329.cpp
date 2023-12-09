//
// Created by 徐浩闻 on 2023/12/9.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, vector<int>> vs;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                vs[i-j].emplace_back(mat[i][j]);
            }
        }
        for (auto &item: vs) sort(item.second.rbegin(), item.second.rend());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = vs[i-j].back();
                vs[i-j].pop_back();
            }
        }
        return mat;
    }
};

int main() {


}