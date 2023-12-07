//
// Created by 徐浩闻 on 2023/12/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int dfs(int from, int to, vector<pair<int, int>> roads[]) {
        int ans = 0;
        for (const auto &city: roads[from]) {
            if(to != city.first) {
                ans+= city.second + dfs(city.first, from, roads);
            }
        }
        return ans;

    }
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<pair<int, int>> roads[n];
        for (const auto &connection: connections) {
            int a = connection[0], b = connection[1];
            roads[a].emplace_back(b, 1);
            roads[b].emplace_back(a, 0);
        }
        return dfs(0, -1, roads);

    }
};

int main() {


}