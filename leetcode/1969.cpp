//
// Created by 徐浩闻 on 2024/3/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
    const int mod = 1000000007;

    long long pow(long long x, int p) {
        x %= mod;
        long long ans = 1;
        while (p--) {
            ans = ans * x % mod;
            x = x * x % mod;
        }
        return ans;
    }

public:
    int minNonZeroProduct(int p) {
        long long k = (1LL << p) - 1;
        return k % mod * pow(k-1, p-1)%mod;
    }
};

int main() {


}
