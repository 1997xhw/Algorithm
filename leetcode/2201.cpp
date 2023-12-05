//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig) {
        int map[1001][1001];
        memset(map, 0, sizeof map);
        for (const auto &item: dig) {
            map[item[0]][item[1]]++;
        }
        int ans = 0;
        for (const auto &artifact: artifacts) {
            int flag = 0;
            int li = artifact[0], lj = artifact[1];
            int ri = artifact[2], rj = artifact[3];
            for (int i = li; i <= ri; i++) {
                for (int j = lj; j <= rj; ++j) {
                    if (map[i][j] == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag==1) break;
            }
            if (flag==0) ans++;
        }

        return ans;
    }
};

int main() {


}