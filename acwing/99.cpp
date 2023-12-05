#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, r, t;
int mm[N][N];
int main() {
    cin >> n >> r;
    if (r == 0) {
        cout << 0;
        return 0;
    }
    memset(mm, 0, sizeof mm);
    for (int i = 0; i < n; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        mm[x + 1][y + 1] += w;
    }
    for (int i = 1; i <= 5001; i ++) {
        for (int j = 1; j <= 5001; j ++) {
            mm[i][j] += mm[i - 1][j] + mm[i][j - 1] - mm[i - 1][j - 1]; 
        }
    }
    int ans = 0;
    if (r > 5000) {
        cout << mm[5001][5001];
        return 0;
    }
    for (int i = r; i <= 5001; i ++) {
        for (int j = r; j <= 5001; j ++) {
            ans = max(ans, mm[i][j] - mm[i - r][j] - mm[i][j - r] + mm[i - r][j - r]);
        }
    }
    
    cout << ans;
    
    
}
