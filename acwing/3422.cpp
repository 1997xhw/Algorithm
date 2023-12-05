#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, x;
vector<int> g[N];
int dfs (int u) {
	int ans = 0;
	int cnt  = g[u].size();
	for (int i = 0;  i < g[u].size(); i ++)
		ans = max(ans, dfs(g[u][i])  + cnt);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i ++) {
		scanf("%d", &x);
		g[x].push_back(i);
	}
	cout << dfs(1) << endl;
	
	return 0;
}
