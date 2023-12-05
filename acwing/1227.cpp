#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, k;
int H[N], W[N];

bool check(int mid) {
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        if(mid > H[i] || mid > W[i]) continue;
        sum += (H[i] / mid) * (W[i] / mid);
    }
    if (sum < k) return false;
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> H[i] >> W[i];
    }
    int l = 1, r = 1e5;
    while(l < r) {
        int mid = l + r + 1>> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
}
