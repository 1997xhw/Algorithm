#include<bits/stdc++.h>
using namespace std;

int n;
int p[10005];
int main() {
	memset(p, 0, sizeof p);
	cin >> n;	for (int i = 1; i <= n; i ++)
		cin >> p[i];
	int res = 0;
	for (int i = 1; i <=n; i ++) {
		int MIN = 10005, MAX = -1;
		for (int j = i; j <=n ; j ++) {
			MAX = max(MAX, p[j]);
			MIN = min(MIN, p[j]);
			if((MAX - MIN) == (j - i)) res ++;

		}
	}
	cout << res << endl;
	return 0;
}

