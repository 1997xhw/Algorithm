//
// Created by 徐浩闻 on 2024/2/27.
//
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:

    int numRollsToTarget(int n, int k, int target) {
        if (n * k < target || target < n) return 0;

        vector<vector<int>> memo(n + 1, vector<int>(target - n + 1, -1));
        const int MAX = 1e9 + 7;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == 0) return j == 0;
            int &res = memo[i][j];
            if (res != -1) {
                return res;
            }
            res = 0;
            for (int x = 0; x < k && x <= j; x++) {
                res = (res + dfs(i - 1, j - x)) % MAX;
            }
            return res;
        };
        return dfs(n, target - n);

    }
};

int main() {
    Solution s;
    cout << s.numRollsToTarget(30, 30, 500);

}