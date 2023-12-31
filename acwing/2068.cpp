#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, k;
int a[N];
int h[11][N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i ++) {
		LL t = a[i] % k; 
		for (int j = 0; j < 11; j ++) {
			h[j][t] ++;
			t = t * 10 % k;
		}
	}
	LL res = 0;
	for (int i = 0; i < n; i ++) {
		LL t = a[i] % k;
		int len = to_string(a[i]).size();
		res += h[len][(k - t) % k];
		LL r = t;
		while(len --) r = r * 10 % k;
		if (r == (k - t) % k) res --;
	}
	cout << res;

	return 0;
}
