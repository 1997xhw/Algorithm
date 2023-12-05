#include<bits/stdc++.h>
using namespace std;
int n;
int f[100005];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;  
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) scanf("%d", &f[i]);
	sort(f + 1, f + n + 1);
	int g = 0;
	for (int i = 2; i <= n; i ++) g = gcd(g, f[i] - f[1]);
	if(!g) cout << n << endl;
	else cout << (f[n] - f[1]) / g + 1 << endl;
	
	
	return 0;
}
