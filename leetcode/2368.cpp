//
// Created by 徐浩闻 on 2024/3/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        set<int> rmp;
        for (auto &item: restricted) {
            rmp.insert(item);
        }
        vector<vector<int>> mp(n + 1);
        for (auto &edge: edges) {
            if (rmp.count(edge[0]) || rmp.count(edge[1])) continue;
            mp[edge[0]].emplace_back(edge[1]);
            mp[edge[1]].emplace_back(edge[0]);

        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(n + 1, false);
        vector<int> ans;
        ans.emplace_back(0);
        while (!q.empty()) {
            auto tmp = q.front();
            vis[tmp] = true;
            q.pop();
            for (auto &item: mp[tmp]) {
                if (!vis[item]) {
                    ans.emplace_back(item);
                    q.push(item);
                }
            }

        }
        return ans.size();
    }
};

int main() {


}