#include<bits/stdc++.h>
using namespace std;
int n, m, qq, x1, y1, x2, y2, c;
int q[1001][1001], s[1001][1001];
void insert(int x1, int y1, int x2, int y2, int c) {
	s[x1][y1] += c;
	s[x1][y2 + 1] -= c;
	s[x2 + 1][y1] -= c;
	s[x2 + 1][y2 + 1] +=c;
}
int main() {
	cin >> n >> m >> qq;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			scanf("%d", &q[i][j]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			insert(i, j, i, j, q[i][j]);
		}
	}
	while(qq--) {
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		insert(x1, y1, x2, y2, c);
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1] + s[i][j];
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cout << q[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
