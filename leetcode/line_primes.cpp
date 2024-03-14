//
// Created by 徐浩闻 on 2024/2/25.
//
#include "bits/stdc++.h"

using namespace std;

int main() {

    const int mx = 1e6;
    int cnt = 0;
    bool vis[mx] = {};
    vector<int> primes;
    for (int i = 2; i <= mx; i++) {
        if (!vis[i]) {
            vis[i] = true;
            cnt++;
            primes.emplace_back(i);
        }
        for (int j = 1; j <= cnt && i * primes[j] <= mx; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }

}