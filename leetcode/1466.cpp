//
// Created by 徐浩闻 on 2024/1/29.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<pair<int, int>> mp[n];
        for (auto &connection: connections) {
            mp[connection[0]].emplace_back(connection[1], 1);
            mp[connection[1]].emplace_back(connection[0], 0);
        }
        function<int(int, int)> dfs = [&](int a, int b) -> int {
            int cnt = 0;
            for (auto &[fr, to]: mp[a]) {
                if (fr != b) {
                    cnt += to + dfs(fr, a);
                }
            }
            return cnt;
        };
        return dfs(0, -1);

    }
};

int main() {


}