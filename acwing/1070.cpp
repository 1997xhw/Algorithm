#include<bits/stdc++.h>
using namespace std;
const int N = 110, INF = 100000000;
int n;
int f[N][N];
bool is_match(char l, char r) {
	if (l == '(' && r == ')') return true;
	if (l == '[' && r == ']') return true;
	return false;
}
int main() {
	string s;
	cin >> s;
	n = s.size();

	for (int len = 1; len <= n; len ++)
		for (int i = 0; i + len - 1 < n; i ++) {
			int j = i + len - 1;
			f[i][j] = INF;
			if (is_match(s[i], s[j])) f[i][j] = f[i + 1][j - 1];
			f[i][j] = min(f[i][j], min(f[i][j - 1], f[i + 1][j]) + 1);
			for (int k = i; k < j; k ++)
				f[i][j] = min(f[i][j], f[i][k] +f[k + 1][j]);
		}
	cout << f[0][n - 1] << endl;
	return 0;
}
