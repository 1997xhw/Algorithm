#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e5 + 10, M = (1 << 20) + 10;
int n, m, x;
int last[M], g[N];

int main() {
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i ++) {
		int a;
		scanf("%d", &a);
		g[i] = max(g[i - 1], last[a ^ x]);
		last[a] = i;
	}
	while( m --) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (g[r] >= l) puts("yes");
		else puts("no");
	}
	
	return 0;
}
