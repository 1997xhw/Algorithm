#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int dx[] = {0, 1, 0, 0, 0, -1};
int dy[] = {1, 0, 0, -1, 0, 0};
int dz[] = {0, 0, 1, 0, -1, 0};
int sx,sy,sz,ex,ey,ez;  //pi为S的位置，ei为E的位置
int l, r, c;
char f[105][105][105];
bool vis[105][105][105];
int dis[105][105][105];

struct Node {
	int x, y, z;
};
int bfs(Node start, Node end) {
	queue<Node> q;
	q.push(start);
	vis[start.x][start.y][start.z] = true;
	while(!q.empty()) {
		Node u = q.front();
		q.pop();
		for (int i = 0; i < 6; i ++) {
			int x = dx[i] + u.x, y = dy[i] + u.y, z = dz[i] + u.z;
			if (x < 1 || x > l || y < 1 || y > r || z < 1 || z > c) continue;
			if (vis[x][y][z]) continue;
			if (f[x][y][z] != '#') {
				Node n = {x, y, z};
				q.push(n);
				vis[x][y][z] = true;
				dis[x][y][z] = dis[u.x][u.y][u.z] + 1;
			}
			if (x == end.x && y == end.y && z == end.z) return dis[x][y][z];
		}
	}
	return 0;
}
int main() {
	while(1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		memset(f, 0, sizeof f);
		memset(vis, false, sizeof vis);
		memset(dis, 0, sizeof dis);
		Node start, end;
		for(int i= 1; i<=l; i++) {
			for(int j= 1; j<=r; j++) {
				for(int k= 1; k<=c; k++) {
					cin >> f[i][j][k];
					if(f[i][j][k]=='S') start.x = i, start.y = j, start.z = k;
					if(f[i][j][k]=='E') end.x = i, end.y = j, end.z = k;
				}
			}
		}
		int cnt = bfs(start, end);
		if(cnt!=0) printf("Escaped in %d minute(s).\n",cnt);
		else cout<<"Trapped!"<<endl;


	}
	return 0;
}




