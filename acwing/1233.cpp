#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, total, bound;
char f[N][N];
bool vis[N][N];
typedef pair<int, int> PII;
int dir[] = {-1, 0, 1, 0, -1};
void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i ++) {
		int xx = x + dir[i], yy = y + dir[i + 1];
		if (xx >= 0 && yy >= 0 && xx < n && yy < n && f[xx][yy] == '#' && !vis[xx][yy]) {
			bool ok = true;
			for (int j = 0; j < 4; j ++) {
				int xxx = xx + dir[j], yyy = yy + dir[j + 1];
				if(xxx >= 0 && yyy >= 0 && xxx < n && yyy < n && f[xxx][yyy] == '.') ok = false;
			}
			if (!ok) bound ++;
			total ++;
			dfs(xx, yy);

		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			cin >> f[i][j];

	memset(vis, false, sizeof vis);
	int cnt = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++) {
			if (f[i][j] == '#' && !vis[i][j]) {
				total = 1, bound = 1;
				dfs(i, j);
				if (total == bound) cnt ++;
			}
		}

	cout << cnt << endl;

	return 0;
}
