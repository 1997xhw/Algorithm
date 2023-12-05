#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000010;
int n;
int tr[N], sum[N], h[N];
int lowbit(int x) {
	return x & -x;
}
int query(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}
int add(int x, int v) {
	for (int i = x; i < N; i += lowbit(i)) tr[i] += v;
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i ++)	scanf("%d", &h[i]), h[i] ++;
	//求每个数前面又多少个数比它大
	for (int i = 0; i < n; i ++) {
		sum[i] = query(N - 1) - query(h[i]);
		add(h[i], 1);
	}
	memset(tr, 0, sizeof tr);
	//每个数后面又多少个数比他小 
	for (int i = n - 1; i >= 0; i --) {
		sum[i] += query(h[i] - 1);
		add(h[i], 1);
	}
	LL res = 0;
	for (int i = 0; i < n; i ++) res += (LL)sum[i] * (sum[i] + 1) / 2;
	cout << res << endl;
	return 0;
}
