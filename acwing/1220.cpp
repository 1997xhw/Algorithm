#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 +10, M = N * 2;
int n;
int e[M], ne[M], w[N], idx, h[N];
LL f[N];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u, int father) {
	f[u] = w[u];
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (father == j) continue;
		dfs(j, u);
		f[u] += max(0ll, f[j]);
	}
}
int main() {
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	idx = 0;
	for (int i = 0; i < n - 1; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	dfs(1, -1);
	LL res = f[1];
	for (int i = 2; i <= n; i ++) res = max(res, f[i]);
	cout << res << endl;

	return 0;
}
