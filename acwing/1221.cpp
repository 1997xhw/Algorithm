#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int n, t;
int h[N];

int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int c = 0; c * c <= n; c ++) {
        for (int d = c; c * c + d * d <= n; d++) {
            t = c * c + d * d;
            if(h[t] == -1) h[t] = c;
        }
    }
    
    for (int a = 0; a * a <= n; a ++) {
        for (int b = a; a * a + b * b <= n; b ++) {
            t = n - a * a - b * b;
            int c = h[t];
            if (c == -1) continue;
            int d = sqrt(t - (c * c));
            cout << a << " " << b << " " << c << " " << d;
            return 0;
        }
    }
    
    
}
