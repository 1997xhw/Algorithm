//
// Created by 徐浩闻 on 2023/12/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        int ns_top[10] = {0}, ns_bottom[10] = {0};

        int num = -1, len = tops.size();
        for (auto &top: tops) ns_top[top]++;
        for (auto &bottom: bottoms) ns_bottom[bottom]++;
        for (int i = 1; i <= 6; i++) {
            if (ns_top[i] + ns_bottom[i] >= len) {
                num = i;
                break;
            }
        }
        if (num == -1) return -1;
        int top = 0, bo = 0;
        for (int i = 0; i < len; i++) {
            if (tops[i] != num && bottoms[i] != num) return -1;
            if (tops[i] == num) top++;
            if (bottoms[i] == num) bo++;
        }
        return len - max(top, bo);
    }
};

int main() {
    vector<int> tops = {1, 2, 1, 1, 1, 2, 2, 2};
    vector<int> bottoms = {2, 1, 2, 2, 2, 2, 2, 2};
    Solution s;
    cout << s.minDominoRotations(tops, bottoms);


}