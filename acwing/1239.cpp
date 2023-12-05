#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1000000009; 
int n, k;
int a[N];
typedef long long LL;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	sort(a, a + n);
	int res = 1, l = 0, r = n - 1;
	int sign = 1;
	if(k % 2) {
		res = a[r --];
		k --;
		if (res < 0) sign = -1;
	}
	while (k) {
		LL x = (LL)a[l] * a[l + 1], y = (LL)a[r - 1] * a[r];
		if(x * sign > y * sign) {
			res = x % MOD * res % MOD;
			l += 2;
		} else {
			res = y % MOD * res % MOD;
			r -= 2;
		}
		k -= 2;
	}
	
	cout << res << endl;
	return 0;
}
