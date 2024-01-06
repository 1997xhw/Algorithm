//
// Created by 徐浩闻 on 2023/12/27.
//
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100005];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
    }
    int mm = 0;
    int i = 0, j = 1;
    while (j < n - 1) {
        if (a[j] - a[j - 1] != 1) {
            mm = max(mm, j - i);
            i = j;
        }
        j++;
    }
    mm = max(mm, j - i);
    cout << mm << endl;
}