#include<bits/stdc++.h>
using namespace std;
const int INF= 0x7f;
int minSteps(int n) {
	int f[n+1][n+1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = INF;
		}
	}
	f[1][0] = 0;
	f[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		int minn = INF;
		for (int j = 0; j <= i / 2; j++) {
			f[i][j] = f[i - j][j] + 1;
			minn = min(minn, f[i][j]);
		}
		f[i][i] = minn + 1;
	}
	int ans = INF;
	for ( int i = 0; i <= n; i++) ans = min(ans, f[n][i]);
	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << minSteps(n);


}