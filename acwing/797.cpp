#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int l, r, c;
int nn[N], cc[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <=n; i ++) scanf("%d", &nn[i]);
	cc[1] = nn[1];
	for (int i = 2; i <= n; i ++) cc[i] = nn[i] - nn[i - 1];
	for (int i = 0; i < m; i ++) {
		scanf("%d%d%d", &l, &r, &c);
		cc[l] += c;
		cc[r + 1] -= c;
	}
	int ans = 0;
	for (int i = 1; i <=n; i ++) {
		ans += cc[i];
		printf("%d ", ans);
	}
	return 0;
}
