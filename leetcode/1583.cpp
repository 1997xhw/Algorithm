//
// Created by 徐浩闻 on 2024/2/29.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs) {
        unordered_map<int, unordered_set<int>> hp;
        for (auto i: pairs) {
            for (auto j: preferences[i[0]]) {
                if (j == i[1]) break;
                hp[i[0]].insert(j);
            }
            for (auto j: preferences[i[1]]) {
                if (j == i[0]) break;
                hp[i[1]].insert(j);
            }
        }
        int ans = 0;
        for (auto it = hp.begin(); it != hp.end(); ++it) {
            for(auto i:it->second) {
                if(hp.find(i)!=hp.end()) {
                    if(hp[i].count(it->first)) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {


}