//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;
bool is_prime(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int lnn(long long a, long long b) {
    for (long long i = b; i > a; --i) {
        if (is_prime(i)) return i;
    }
    return -1;
}
int main() {
    long long a, b;
    cin >> a >> b;
    cout << lnn(a, b) << endl;
    return 0;
}