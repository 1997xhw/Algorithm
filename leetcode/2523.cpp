//
// Created by 徐浩闻 on 2024/2/25.
//
#include "bits/stdc++.h"

using namespace std;

const int MX = 1e6;
vector<int> primes;

int init () {
    bool np[MX + 1]{};
    for (int i = 2; i <= MX; ++i) {
        if (!np[i]) {
            primes.emplace_back(i);
            for (int j = i; j <= MX / i; ++j) {
                np[i * j] = true;
            }
        }
    }
    primes.emplace_back(MX + 1);
    primes.emplace_back(MX + 1);
    return 0;
};

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        init();
        int p = -1, q = -1;
        int  i = lower_bound(primes.begin(), primes.end(), left) -primes.begin();
        for (; primes[i+1]<=right;++i) {
            if (p < 0|| primes[i+1]-primes[i] < q-p){
                p = primes[i];
                q =  primes[i + 1];
            }
        }
        return {p, q};
    }
};

int main() {


}