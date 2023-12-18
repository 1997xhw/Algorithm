//
// Created by 徐浩闻 on 2023/12/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> num_count(n * n + 1, 0);
        for (auto &row: grid) {
            for (int num: row) {
                num_count[num]++;
            }
        }
        int rr = 0, mm = 0;
        for (int i = 1; i <= n * n; ++i) {
            if (num_count[i] == 2) {
                rr = i;
            } else if (num_count[i] == 0) {
                mm = i;
            }
        }
        return {rr, mm};
    }


};

int main() {


}