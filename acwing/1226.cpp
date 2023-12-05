#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int n;
int A[110];
bool f[110][N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int n;
	cin >> n;
	int d = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &A[i]);
		d = gcd(d, A[i]);
	}

	if (d != 1) puts("INF");
	else {
		f[0][0] = true;
		for (int i = 1; i <= n; i ++)
			for (int j = 0; j < N; j ++) {
				f[i][j] = f[i - 1][j];
				if (j >= A[i]) f[i][j] |= f[i][j - A[i]];
			}
		int res = 0;
		for (int i = 0; i < N; i ++) if (!f[n][i]) res ++;
		cout << res << endl;
	}


	return 0;
}
