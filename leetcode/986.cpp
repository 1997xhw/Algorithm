//
// Created by 徐浩闻 on 2023/12/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> ans;
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            int a = firstList[i][0], b = firstList[i][1];
            int aa = secondList[j][0], bb = secondList[j][1];
            vector<int> tmp = {max(a, aa), min(b, bb)};
            if (tmp[1]>=tmp[0]) ans.emplace_back(tmp);
            if (bb>=b) i++;
            else j++;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> firstList = {{0,  2},
                                     {5,  10},
                                     {13, 23},
                                     {24, 25}};
    vector<vector<int>> secondList = {{1,  5},
                                      {8,  12},
                                      {15, 24},
                                      {25, 26}};

}