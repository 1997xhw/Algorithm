#include<bits/stdc++.h>
using namespace std;
const int N = 55, MOD = 1000000007;
int n, m, k;
int T[N][N];
int f[N][N][13][14];
//所有从起点走到(i, j), 且已经取了k件物品,且最后一件物品的价值是C的合法方案的集合 


int main() {
	cin >> n >> m >> k;
	memset(T, 0, sizeof T);
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> T[i][j];
			T[i][j] ++;      
		}
	}
	f[1][1][1][T[1][1]] = 1;
	f[1][1][0][0] = 1;
	for (int i = 1; i <= n; i ++) {  
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			for (int u = 0; u <= k; u ++) {
				for (int v = 0; v <= 13 ; v ++) {
					int &val = f[i][j][u][v];
					val = (val + f[i - 1][j][u][v]) % MOD;//从上边走下来 此时不取 
					val = (val + f[i][j - 1][u][v]) % MOD;//从左边走下来 此时不取
					if(u > 0 && v == T[i][j]){
						for (int c = 0; c < v; c ++) {
							val = (val + f[i - 1][j][u - 1][c]) % MOD; 
							val = (val + f[i][j - 1][u - 1][c]) % MOD;
						}
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= 13; i ++)
	res = (res + f[n][m][k][i]) % MOD; 
	cout << res << endl;
	return 0;
}
