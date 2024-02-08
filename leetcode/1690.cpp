//
// Created by 徐浩闻 on 2024/2/3.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int> &stones) {
        int n = stones.size();
        vector<int> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(prefix[j + 1] - prefix[i + 1] - dp[i + 1][j], prefix[j] - prefix[i] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }

    int stoneGameVII_memo(vector<int> &stones) {
        int n = stones.size();
        vector<int> prefix(n + 1);
        map<pair<int, int>, int> memo;
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == j) return 0;
            if (memo.count({i, j})) return memo[{i, j}];
            int scoreRemoveFirst = prefix[j + 1] - prefix[i + 1] - dfs(i + 1, j);
            int scoreRemoveLast = prefix[j] - prefix[i] - dfs(i, j - 1);
            memo[{i, j}] = max(scoreRemoveFirst, scoreRemoveLast);
            return memo[{i, j}];
        };

        return dfs(0, n - 1);

    }
};

int main() {
    vector<int> stones = {792, 195, 697, 271, 743, 51, 836, 322, 135, 550, 399, 182, 988, 25, 395, 254, 480, 931, 513,
                          772, 798, 102, 110, 915, 794, 330, 597, 220, 789, 462};
    Solution s;
    cout << s.stoneGameVII(stones);

}