#include<bits/stdc++.h>
using namespace std;
int n, m, l, r;
const int N = 100005;
int num[N], nn[N];
int main(){
    cin >> n >> m;
    for (int i = 1; i <=n; i ++) {
        cin >> num[i];
    }
    memset(nn, 0, sizeof nn);
    for (int i = 1; i <=n; i++) {
        nn[i] = nn[i - 1] + num[i];
    }
    for (int i = 0; i < m; i ++) {
        cin >> l >> r;
        cout << nn[r] - nn[l - 1] << endl;
    }
    
}
