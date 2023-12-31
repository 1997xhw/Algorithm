#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int w[N];
struct Node {
	int l, r, m;
} tr[4 * N];

void pushup(int u) {
	tr[u].m = max(tr[u << 1].m, tr[u << 1 | 1].m);
}

void build(int u, int l, int r) {
	if (l == r) tr[u] = {l, r, w[r]};
	else {
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].m;
	int mid = tr[u].l + tr[u].r >> 1;
	int mmax = INT_MIN;
	if(l <= mid) mmax = max(mmax, query(u << 1, l, r));
	if(r > mid) mmax = max(mmax, query(u << 1 | 1, l, r));
	return mmax;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	build(1, 1, n);
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", query(1, x, y));
//		cout << query(1, x, y) << endl;
	}
}
