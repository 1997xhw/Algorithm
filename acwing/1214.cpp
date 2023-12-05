#include<bits/stdc++.h>
using namespace std;
const int N = 1005, MOD = 100000007;
int n, s, a, b;
int f[N][N];
int get_mod(int a, int b) {
	return (a % b + b) % b;
}
int main() {
	cin >> n >> s >> a >> b;
	f[0][0] = 1;
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < n; j ++) {
			f[i][j] = (f[i - 1][get_mod(j - i * a, n)] + f[i - 1][get_mod(j + i * b, n)]) % MOD;
		}
	}
	cout << f[n - 1][get_mod(s, n)] << endl;
	return 0;
}
