#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200010;
int n, m;
int a[N];
int main() {
	cin >> n >> m;
	int k = n + m + 1;
	for (int i = 0; i < k; i ++) cin >> a[i];
	LL res = 0;
	if (!m) {
		for (int i = 0; i < k; i ++) res += a[i];
	} else {
		sort(a, a + k);
		res = a[k - 1] - a[0];
		for (int i = 1; i < k - 1; i ++) res += abs(a[i]);
	}
	printf("%lld\n", res);
	return 0;
}
