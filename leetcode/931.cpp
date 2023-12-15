//
// Created by 徐浩闻 on 2023/12/14.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[0][i] = matrix[0][i];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mi = dp[i - 1][j];
                if (j > 0) mi = min(dp[i - 1][j - 1], mi);
                if (j + 1 < n) mi = min(mi, dp[i-1][j + 1]);
                dp[i][j] = mi + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) ans = min(ans, dp[m - 1][i]);
        return ans;
    }
};

int main() {
    vector<vector<int>> nums = {{2, 1, 3},
                                {6, 5, 4},
                                {7, 8, 9}};
    Solution s;
    cout << s.minFallingPathSum(nums) << endl;

}