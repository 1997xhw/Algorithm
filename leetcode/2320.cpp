//
// Created by 徐浩闻 on 2024/1/8.
//z
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int countHousePlacements(int n) {
        long long fi[2] = {2, 3};
        if (n == 1) return 4;
        if (n == 2) return 9;
        for (int i = 3; i <= n; i++) {
            long long tmp = fi[0];
            fi[0] = fi[1];
            fi[1] = (tmp + fi[0]) % mod;
        }
        return (fi[1] * fi[1]) % mod;
    }
};

int main() {


}