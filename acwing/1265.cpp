#include<bits/stdc++.h>
using namespace std;
const int N = 32010;
int n, x, y;
int tr[N], level[N];
int lowbit(int x) {
	return x & -x;
}
int treeSum(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}
void treeAdd(int x) {
	for (int i = x; i <= N; i += lowbit(i)) tr[i] ++;
}
int main() {
	cin >> n;
	memset(level, 0, sizeof level);
	for (int i = 0; i < n; i ++) {
		cin >> x >> y;
		x ++;
		level[treeSum(x)] ++;
		treeAdd(x);
	}
	
	for (int i = 0; i < n; i ++) cout << level[i] << endl;
	return 0;
}
