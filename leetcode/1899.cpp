//
// Created by 徐浩闻 on 2024/1/29.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        vector<bool> ans = {false, false, false};
        for (auto &tri: triplets) {
            if (tri[0] <= target[0] && tri[1] <= target[1] && tri[2] <= target[2]) {
                ans[0] = ans[0] || tri[0]==target[0];
                ans[1] = ans[1] || tri[1]==target[1];
                ans[2] = ans[2] || tri[2]==target[2];
            }
        }
        return ans[0] && ans[1] &&ans[2];
    }
};

int main() {


}