#include<bits/stdc++.h>
using namespace std;

int n, v;
int V[1005], W[1005];
int f[1005][1005];
int ff[1005];
int main() {
	cin >> n >> v;
	//二维版本 
	for(int i = 1; i <= n; i ++) {
		cin >> V[i] >> W[i];
	}
	f[0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for(int j = 0; j <= v ; j ++) {
			f[i][j] = f[i - 1][j];
			if (j >= V[i])
				f[i][j] = max(f[i][j], f[i - 1][j - V[i]] + W[i]);
		}
	}
	//一维版本 
	for(int i = 1; i <= n; i++) {
		for (int j = v; j >= V[i]; j --)
			f[j] = max[f[j], f[j - V[i]] + W[i]];
	} 
	
	int ans = 0;
	for (int i = 0; i <= v; i ++)
		ans = max(ans, f[n][i]);
	cout << ans; 
}
