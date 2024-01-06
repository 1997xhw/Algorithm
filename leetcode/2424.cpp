//
// Created by 徐浩闻 on 2024/1/4.
//
#include "bits/stdc++.h"

using namespace std;

class LUPrefix {
public:
    int r;
    vector<int> mp;

    LUPrefix(int n) {
        r = 0;
        mp.resize(n+5, 0);
    }

    void upload(int video) {
        mp[video] = 1;
        while (mp[r + 1] == 1) r++;
    }

    int longest() {
        return r;
    }
};

int main() {


}