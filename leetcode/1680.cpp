//
// Created by 徐浩闻 on 2024/1/26.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
    static constexpr int mod = 1000000007;
public:
    int concatenatedBinary(int n) {
        int ans = 0, shi = 0;
        for (int i = 1; i <= n; i++) {
            if (!(i & (i - 1))) {
                shi++;
            }
            ans = ((static_cast<long long>(ans) << shi) + i) % mod;
        }
        return ans;
    }
};

int main() {


}