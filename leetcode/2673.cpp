//
// Created by 徐浩闻 on 2024/2/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int> &cost) {
        int len = cost.size();
        int cnt = 0;
        function<int(int)> dfs = [&](int a) -> int {
            if (a * 2 + 1 > len - 1) return cost[a];
            else {
                int l = dfs(a * 2 + 1);
                int r = dfs(a * 2 + 2);
//                cout << a << " " << l << " " << r << endl;
                cnt += abs(l - r);
//                cost[a] = max(l, r);
                return cost[a]+max(l, r);
            }
        };
        dfs(0);
        return cnt;
    }
};

int main() {
    vector<int> cost = {5,3,3};
    Solution s;
    cout << s.minIncrements(3, cost);

}
