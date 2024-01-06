//
// Created by 徐浩闻 on 2024/1/4.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        int rows[m];
        memset(rows, 0, sizeof rows);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) rows[i] |= 1 << j;
            }
        }
        int ans = 0;
        for (int i = 1; i < 1 << n; i++) {
            if (__builtin_popcount(i) != numSelect) continue;
            int t = 0;
            for (int j = 0; j < m; ++j) {
                t += (rows[j] & i) == rows[j];
            }
            ans = max(ans, t);
        }
        return ans;
    }
};

int main() {


}