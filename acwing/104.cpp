#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;
int n;
int x[N];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &x[i]);
	sort(x, x + n);
	int c = x[n / 2];
	LL res = 0;
	for (int i = 0; i <n; i ++) res += abs(x[i] - c);
	cout << res << endl;
	return 0;
}
