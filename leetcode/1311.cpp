//
// Created by 徐浩闻 on 2024/2/26.
//
#include "bits/stdc++.h"

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

class Solution {
public:


    vector<string>
    watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level) {
        int fmap[101][101];
        memset(fmap, 0, sizeof fmap);
        int m = friends.size();
        for (int i = 0; i < m; i++) {
            int n = friends[i].size();
            for (int j = 0; j < n; j++) {
                fmap[i][friends[i][j]] = 1;
                fmap[friends[i][j]][i] = 1;
            }
        }
        vector<int> vis(101, 0); // 记录是否访问过
        queue<int> q;
        q.push(id);
        vis[id] = 1;
        int l = 0;
        while (!q.empty() && l < level) {
            int size = q.size();
            while (size--) {
                int t = q.front();
                q.pop();
                for (int i = 0; i < 101; i++) {
                    if (fmap[t][i] == 1 && !vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            l++;
        }
        map<string, int> mp;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto &item: watchedVideos[t]) {
                mp[item]++;
            }
        }
        vector<pair<string, int>> items(mp.begin(), mp.end());
        sort(items.begin(), items.end(), cmp);
        vector<string> ans;
        for (const auto &item: items) ans.emplace_back(item.first);
        return ans;
    }
};

int main() {


}