//
// Created by 徐浩闻 on 2024/1/4.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct un {
        int fa = -1;
        long long cnt = 1;
    };
    vector<un> mp;

    int find(int i) {
        if (mp[i].fa != -1) return find(mp[i].fa);
        else return i;
    }

    void uni(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            mp[rootA].fa = rootB;
            mp[rootB].cnt += mp[rootA].cnt;
        }
    }

    long long getCount(int i) {
        int root = find(i);
        return mp[root].cnt;
    }

    long long countPairs(int n, vector<vector<int>> &edges) {
        mp.resize(n);
        for (auto &e: edges) {
            uni(e[0], e[1]);
        }
        vector<long long> li;
        long long res = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mp[i].fa == -1) {
                res += mp[i].cnt* sum;
                sum+= mp[i].cnt;
            }

        }
        return res;
    }
};

int main() {


}