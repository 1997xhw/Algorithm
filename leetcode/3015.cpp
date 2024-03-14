//
// Created by 徐浩闻 on 2024/2/29.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<long long>> maps(n + 1, vector<long long>(n + 1, INT_MAX));
        for (int i = 0; i < n; i++) {
            maps[i][i + 1] = 1;
            maps[i + 1][i] = 1;
        }
        maps[x][y] = 1;
        maps[y][x] = 1;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (maps[i][j] > maps[i][k] + maps[k][j])
                        maps[i][j] = maps[i][k] + maps[k][j];
                }
            }
        }
        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j and maps[i][j] != INT_MAX) {
                    ans[maps[i][j] - 1]++;
                }
            }
        }
        return ans;
    }
};

int main() {


}