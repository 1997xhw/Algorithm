#include<bits/stdc++.h>
using namespace std;
const int N = 353;
int n, m;
int f[N][N], V;
int main() {
	cin >> n >> m;
//	for (int i = 1; i <= n;i ++) f[i][1] = 1;
//	for (int j = 1; j <= m; j ++) f[1][j] = 1;
	f[1][1] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (i == 1 && j == 1) continue;
			if (i % 2 == 0 && j % 2 == 0) continue;
			if (i - 1 > 0)	f[i][j] += f[i - 1][j];
			if (j - 1 > 0)	f[i][j] += f[i][j - 1];
		}
	}
	cout << f[n][m];




	return 0;
}
