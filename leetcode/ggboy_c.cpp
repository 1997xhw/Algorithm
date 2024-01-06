//
// Created by 徐浩闻 on 2023/12/27.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
    }
    for (int i = 1; i <= n; ++i) {
        int p1, p2, tmp;
        scanf("%d %d", &p1, &p2);
        tmp = a[p1] + a[p2];
        sum += (tmp < a[i] ? tmp : a[i]);
    }
    cout << sum << endl;
    return 0;
}