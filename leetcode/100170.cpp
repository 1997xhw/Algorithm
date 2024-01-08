//
// Created by 徐浩闻 on 2024/1/7.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    pair<float, long long> mm = {0, 0};
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        for (auto &i: dimensions) {
            float x = sqrt(i[0] * i[0] + i[1] * i[1]);
            long long y = i[0] * i[1];
            if ((mm.first == x && mm.second < y) || mm.first < x) {
                mm = {x, y};
            }

        }
        return (int)mm.second;
    }
};
int main() {


}