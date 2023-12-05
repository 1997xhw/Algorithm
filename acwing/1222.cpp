#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int f[1005][1005];
	cin >> s;
	int n = s.size();
	for (int i = 1; i <= n; i ++) {
		for (int l = 0; l + i - 1 < n; l ++) {
			int r = l + i - 1;
			if(i == 1) f[l][r] = 1;
			else {
				if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1] + 2;
				if(f[l + 1][r] > f[l][r]) f[l][r] = f[l + 1][r];
				if (f[l][r - 1] > f[l][r]) f[l][r] = f[l][r - 1];
			}
		} 
		
	}
	printf("%d", n - f[0][n - 1]);
	return 0;
}
