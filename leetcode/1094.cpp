//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int ftmap[1005];
        memset(ftmap, 0, sizeof ftmap);
        for (const auto &trip: trips) {
            int cc = trip[0], ff = trip[1], tt = trip[2];
            ftmap[ff]+=cc;
            ftmap[tt]-=cc;
        }
        int cap = 0;
        for(int i = 0; i < 1005; i ++) {
            cap+=ftmap[i];
            if (cap >capacity) return false;
        }

        return true;

    }
};
int main() {


}