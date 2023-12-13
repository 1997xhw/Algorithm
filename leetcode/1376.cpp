//
// Created by 徐浩闻 on 2023/12/12.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        int ans = 0, tmp;
        for (int i = 0; i < manager.size(); i++) {
            if (i == headID) continue;
            if (informTime[i] == 0) {
                tmp =0;
                int j = manager[i];
                while (j != headID) {
                    tmp+=informTime[j];
                    j = manager[j];
                }
                tmp+=informTime[headID];
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> manager = {2,2,-1,2,2,2};
    vector<int> info = {0,0,1,0,0,0};
    Solution s;
    cout << s.numOfMinutes(6, 2, manager, info);

}