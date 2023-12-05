#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;

    ll f = 0, x = 0;
    while (1) {
        if (f >= n) break;
        f = f * 3 + 1;
        x ++;
    }

    cout << x;

    return 0;
}
