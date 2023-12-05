#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200010, M = N << 1;
int n, m;
int p[N], pp[N];
int h[N], e[M], ne[M], idx;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int father) {
	pp[u] += pp[father];
	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		dfs(j, u);
	} 
}

int find(int x) {
	if(p[x] != x) return p[x] = find(p[x]);
	return p[x];
}
int main() {
	cin >> n >> m;
	 memset(h, -1, sizeof h);
	for (int i = 0; i <= 2 * n; i ++) p[i] = i;
	int root = n + 1;
	while(m --) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t == 1) {
			int fa = find(a), fb = find(b);
			if (fa != fb) {
				p[fa] = p[fb] = root;
				add(root, fa);
				add(root, fb);
				root ++;
			}
		} else if(t == 2) {
			int fa = find(a);
			pp[fa] += b;
		}
	}
	for (int i = n + 1; i < root; i ++)
		if(p[i] == i) dfs(i, 0);
	for (int i = 1; i <= n; i ++)
		printf("%d ", pp[i]);
	return 0;

}
