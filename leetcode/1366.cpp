//
// Created by 徐浩闻 on 2024/1/26.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string rankTeams(vector<string> &votes) {
        vector<vector<int>> rank(27, vector<int>(27, 0));
        string ans;
        for (auto &p: votes) {
            for (int i = 0; i < p.length(); i++) {
                rank[p[i] - 'A'][i]++;
                rank[p[i] - 'A'].back() = 26 - (p[i] - 'A');
            }
        }
        sort(rank.begin(), rank.end(), greater<vector<int>>());
        for (int i = 0; i < rank.size(); i++) {
            if (rank[i].back() != 0) {
                ans.push_back(26 - (rank[i].back() - 'A'));
            }
        }
        return ans;
    }
};

int main() {


}
