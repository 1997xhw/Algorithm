//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        int len = dist.size();
        vector<int> mon;
//        memset(mon, 0, sizeof mon);
        for (int i = 0; i < len; ++i) {
            mon.push_back((dist[i] - 1) / speed[i]);
        }
        sort(mon.begin(), mon.end());
        for (const auto &item: mon)
            cout << item << " ";
        cout << endl;
        for (int i = 0; i < len; ++i) {
            if (mon[i] < i) return i;
        }
        return len;
    }
};

int main() {
    Solution s;
    vector<int> dist{1,2,2,3};
    vector<int> speed{1,1,1,1};
    cout << s.eliminateMaximum(dist, speed) << endl;

}