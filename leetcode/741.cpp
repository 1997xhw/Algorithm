#include<bits/stdc++.h>
using namespace std;

int cherryPickup(vector<vector<int>>& grid) {
	const int N = 55;
	const int INF = -10000;
	int len = grid.size();
	int dp[N][N][N];
	memset(dp, 0x80, sizeof(dp)); //-2139062144, 作用相当于 INT_MIN

	dp[2][1][1] = grid[0][0];// dp[2][1][1] 两个点都在左上角的初始状态，都为0，即 dp[2][1][1] = grid[0][0]
	for (int k = 3; k <= 2*len; k++) {
		for (int i1 = 1; i1 <= len; i1++) {
			for (int i2 = 1; i2 <= len; i2++) {
				//计算两个点所在的列
				int j1 = k - i1, j2 = k - i2;
				if(j1 <= 0 || j1 > len || j2 <= 0 || j2 > len) continue;
				int A = grid[i1 - 1][j1 - 1], B = grid[i2 -1][j2 - 1];
				if(A == -1 || B == -1) continue;
				int a = dp[k - 1][i1 - 1][i2];
				int b = dp[k - 1][i1 - 1][i2 - 1];
				int c = dp[k - 1][i1][i2 - 1];
				int d = dp[k - 1][i1][i2];
				int t = max(max(a, b), max(c, d)) + A;
				if(i1 != i2) t+=B;
				dp[k][i1][i2] = t;
			}
		}
	}
	return dp[2 * len][len][len] <= 0 ? 0 : dp[2 * len][len][len];
}
int main() {

}