#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, k, a, b;
int tree[N], t[N];
int lowbit(int x) {
	return x & -x;
}
int treeSum(int a, int b) {
	int sa = 0, sb = 0;
	for (int i = a - 1; i; i -= lowbit(i)) sa+= tree[i];
	for (int i = b; i; i -= lowbit(i)) sb += tree[i];
	return sb - sa;
}
void treeAdd(int a, int b) {
	for (int v = a; v<= n; v += lowbit(v)) tree[v] += b;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)	scanf("%d", &t[i]);
	for (int i = 1; i <= n; i ++)	treeAdd(i, t[i]);
	for (int i = 0; i < m; i ++) {
		scanf("%d%d%d", &k, &a, &b);
		if(k == 1) treeAdd(a, b);
		if(k == 0) cout << treeSum(a, b) << endl;
	}


	return 0;
}
