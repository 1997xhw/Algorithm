//
// Created by 徐浩闻 on 2023/11/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        int map[10005];
        memset(map, 0, sizeof map);
        for (auto edge: edges) {
            map[edge[1]]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (map[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;


}