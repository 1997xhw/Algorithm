#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
int t, r, c;
int m[205][205];
int dis[205][205];
int direct[5] = {-1, 0, 1, 0, -1};

void bfs(PII st, PII en) {
	queue<PII> q;
	q.push(st);
	while(!q.empty()) {
		PII u = q.front();
		q.pop();  
		for (int i = 0; i <= 4; i ++) {
			int x = u.x + direct[i], y = u.y + direct[i + 1];
			if(m[x][y] == -1) continue;
			if(m[x][y] == 1) {
				dis[x][y] = dis[u.x][u.y] + 1;
				m[x][y] = -1;
				q.push({x, y});
			}
			if(x == en.x && y == en.y) {
				cout << dis[x][y] << endl;
				return;
			}
		}
	}
	cout << "oop!" << endl;	
}

int main () {
	cin >> t;
	while(t --) {
		memset(m, -1, sizeof m);
		memset(dis, 0, sizeof dis);
		cin >> r >> c;
		int sx, sy, ex, ey;
		PII st, en;
		for (int i = 1; i <= r; i ++) {
			string s;
			cin >> s;
			for (int j = 1; j <= c; j ++) {
				if(s[j - 1] == '.') m[i][j] = 1;
				if(s[j - 1] == '#') m[i][j] = -1;
				if(s[j - 1] == 'E') m[i][j] = 1, st.x = i, st.y = j;
				if(s[j - 1] == 'S') m[i][j] = 1, en.x = i, en.y = j;
			}
		}
		bfs(st, en);
		
	}

	return 0;
}
