#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int n;
int g[105];
bool f[105][N];
int sum = 0;
int main() {
	cin >> n;
	memset(f, false, sizeof f);
	for (int i = 1; i <= n; i ++) {
	    scanf("%d", &g[i]);
	    sum+=g[i];   
	}

	f[0][0] = true;
	
	for (int i = 1; i <=  n; i ++) {
		for (int j = 0; j <= sum; j ++) {
			f[i][j]=f[i-1][j] || f[i-1][j+g[i]] || f[i-1][abs(j-g[i])];
		}
	}
	int ans = 0;
	for (int i = 1; i <= sum; i ++) if (f[n][i]) ans++;
	cout << ans;
	
	return 0;
}
