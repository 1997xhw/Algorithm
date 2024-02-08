//
// Created by 徐浩闻 on 2024/2/1.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string ans = "";
        dominoes = 'L' + dominoes;
        dominoes = dominoes + 'R';
        int l = 0;
        for (int r = 1; r <= n; r++) {
            if (dominoes[r] == '.')
                continue;
            if (l != 0) {
                ans += dominoes[l];
            }
            int dot = r - l - 1;
            if (dominoes[l] == dominoes[r]) {
                ans += string(dot, dominoes[l]);
            } else if (dominoes[l] == 'L' && dominoes[r] == 'R') {
                ans += string(dot, '.');
            } else {
                ans += string(dot / 2, 'R') + (dot % 2 == 1 ? "." : "") + string(dot / 2, 'L');
            }
            l = r;
        }
        return ans;
    }
};

int main() {


}