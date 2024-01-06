//
// Created by 徐浩闻 on 2023/12/27.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    int a[100005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] <= a[i] && a[i] <= a[i + 1]) {
            res++;
            a[i] = a[i + 1] + 1;
        }
    }
    cout << res << endl;

}