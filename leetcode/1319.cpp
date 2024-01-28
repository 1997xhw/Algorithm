//
// Created by 徐浩闻 on 2024/1/26.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> bcj;
    vector<int> visited;

    void uni(int a, int b) {
        bcj[find(a)] = find(b);
    }

    int find(int a) {
        if (bcj[a] != a) bcj[a] = find(bcj[a]);
        return bcj[a];
    }

    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) return -1;
        for (int i = 0; i < n; i++) {
            bcj.emplace_back(i);
        }
        int cnt = 0;
        for (auto &c: connections) {
            int a = c[0], b = c[1];
            int fa = find(a), fb = find(b);
            if (fa != fb) uni(a, b);
            else {
                cnt++;
            }
        }
        unordered_set<int> ms;
        for (auto &item: bcj) {
            cout << find(item) << " ";
            ms.insert(find(item));
        }
        cout << endl;
        cout << cnt << " " << ms.size()<< endl;
        if (ms.size() - 1 > cnt) return -1;
        else return ms.size() - 1;
    }
};

int main() {
    vector<vector<int>> conn = {{1, 5},
                                {1, 7},
                                {1, 2},
                                {1, 4},
                                {3, 7},
                                {4, 7},
                                {3, 5},
                                {0, 6},
                                {0, 1},
                                {0, 4},
                                {2, 6},
                                {0, 3},
                                {0, 2}};
    Solution s;
    cout << s.makeConnected(12, conn);


}