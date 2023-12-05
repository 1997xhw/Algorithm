#include<bits/stdc++.h>
using namespace std;

int getMoneyAmount(int n) {
	int dp[205][205];
	for (int i = 2; i <= n; i++) {
		for (int l = 1; l + i -1 <=n; l++) {
			int r = l + i - 1;
			dp[l][r] = 0x3f3f3f3f;
			for (int x =  l; x <= r; x++) {
				int cur = max(dp[l][x - 1], dp[x + 1][r]) + x;
				dp[l][r] = min(dp[l][r], cur);
				
			}
		}
	}
	return dp[1][n];


}

int main() {
	int n;
	cin >> n;
	cout << getMoneyAmount(n);
	
}