#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int g[N];
int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) scanf("%d", &g[i]);
	long long res = 0;
	for (int i = 0; i < n - 1; i ++) {
		if (g[i + 1] > g[i]) res += (long long) (g[i + 1] - g[i]); 
	}
	cout << res << endl;
	
	return 0;
} 
