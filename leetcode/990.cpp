//
// Created by 徐浩闻 on 2024/2/1.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> mp;

    int find(int a) {
        if (mp[a] != a) mp[a] = find(mp[a]);
        return mp[a];
    }

    void uni(int a, int b) {
        mp[find(a)] = find(b);
    }

    bool equationsPossible(vector<string> &equations) {
        for (char i = 0; i < 26; i++) {
            mp[i] = i;
        }
        for (auto &st: equations) {
            if (st[1] == '=') {
                uni(st[0] - 'a', st[3] - 'a');
            }
        }
        for (auto &st: equations) {
            if (st[1] == '!') {
                if (find(st[0]-'a')==find(st[3]-'a')) return false;
            }
        }
        return true;
    }
};

int main() {


}