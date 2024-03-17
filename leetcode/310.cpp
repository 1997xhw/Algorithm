//
// Created by 徐浩闻 on 2024/3/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> ans;
        if (n == 1) {
            ans.emplace_back(0);
            return ans;
        }
        vector<int> degree(n, 0);
        vector<vector<int>> mp(n);
        for (auto &item: edges) {
            degree[item[0]]++;
            degree[item[1]]++;
            mp[item[0]].emplace_back(item[1]);
            mp[item[1]].emplace_back(item[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        while (!q.empty()) {
            ans.clear();
            int size = q.size();
            for (int i = 0; i < size; i++) {
                ans.emplace_back(q.front());
                vector<int> tmp = mp[q.front()];
                q.pop();
                for (auto &item: tmp) {
                    degree[item]--;
                    if (degree[item] == 1) q.push(item);
                }
            }
        }
        return ans;

    }
};

int main() {


}