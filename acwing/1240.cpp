#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int T[N];
int main() {
	cin >> n;
	int d = 0, x;
	long long res, tmp;
	res = INT_MIN;
	for (int i = 1, j = 1; i <= n; i ++)
		scanf("%d", &T[i]);
	for (int  d = 1, i = 1; i <= n; d ++, i *= 2) {
		tmp = 0;
		for (int j = i; j < i + (1 << d - 1) && j <= n; j ++ ) tmp += T[j];
		if (tmp > res) {
			res = tmp;
			x = d;
		}
	}
	cout << x << endl;
	return 0;
}
