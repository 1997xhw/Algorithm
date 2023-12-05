//
// Created by 徐浩闻 on 2023/11/11.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
    static const int MAX_N = 500; // 假设最大长度为1000，因此m的最大长度为500
    int p[MAX_N];

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void unions(int a, int b) {
        p[find(a)] = find(b);
    }

public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), m = n / 2;
        for (int i = 0; i < m; i++) p[i] = i;

        for (int i = 0; i < n; i += 2) {
            unions(row[i] / 2, row[i + 1] / 2);
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (i == find(i)) cnt++;
        }
        return m - cnt;
    }
};

int main() {
    Solution s;
    vector<int> row = {0,2,1,3};
    cout << s.minSwapsCouples(row) << endl;

}