#include<bits/stdc++.h>
using namespace std;
string f[25];
bool v[25][25];
typedef pair<int, int> PII;
int direct[5] = {-1, 0, 1, 0, -1};
int w, h, res;

int bfs (PII start) {
	res = 1;
	v[start.first][start.second] = true;
	queue<PII> q;
	q.push(start);

	while(!q.empty()) {
		PII u = q.front();
		q.pop();
		for (int i = 0; i < 4; i ++) {
			int x = u.first + direct[i], y = u.second + direct[i + 1];
			if(x < 0 || x >= h || y < 0 || y >= w) continue;
			if(f[x][y] == '.' && !v[x][y]) {
				v[x][y] = true;
				q.push({x, y});
				res ++;
			}

		}
	}
	return res;
}
int main() {
	while(1) {
		cin >> w >> h;
		if (w == 1 && h == 1) break;
		PII start;
		memset(v, false, sizeof v);
		for (int i = 0; i < h; i ++) cin >> f[i];
		for (int i = 0; i < h; i ++)
			for (int j = 0; j < w; j ++)
				if(f[i][j] == '@') start.first = i, start.second = j;
		cout << bfs(start) << endl;
	}

	return 0;
}
