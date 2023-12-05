#include<bits/stdc++.h>
using namespace std;


int shortestPathAllKeys(vector<string>& grid) {
	vector<int> dirs = {-1, 0, 1, 0, -1};
	int m, n, si = 0, sj = 0, k = 0;
	m = grid.size();
	n = grid[0].size();
	for(int i = 0; i < m; i ++) {
		for(int j = 0; j < n; j ++) {
			char c = grid[i][j];
			if(islower(c)) ++k;
			else if (c == '@') si = i, sj = j;
		}
	}
	queue<tuple<int, int, int>> q {{{si, sj, 0}}};
	vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << k)));//vis表示当前位置(i, j)，当前拥有的钥匙的状态为state时，是否已经被访问过
	vis[si][sj][0] = true;
	int ans = 0;
	while(!q.empty()) {
		for (int t = q.size(); t; --t) {
			auto [i, j, state] = q.front();
			q.pop();
			if(state == (1 << k) - 1) return ans;//如果找到所有钥匙则返回当前步数

			for (int h = 0; h < 4; ++h) {
				int x = i + dirs[h], y = j + dirs[h + 1];//往四个方向搜索
				if (x >= 0 && x < m && y >= 0 && y < n) {
					char c = grid[x][y];

					if(c == '#' || (isupper(c) && (state >> (c - 'A') & 1) == 0)) continue;
					int nxt = state;
					if(islower(c)) nxt |= 1 << (c - 'a');
					if(!vis[x][y][nxt]) {
						vis[x][y][nxt] = true;
						q.push({x, y, nxt});
					}
				}
			}
		}
		ans++;
	}
	return -1;
}
int main() {

	vector<string> s {"@.a.#","###.#","b.A.B"};
	cout << shortestPathAllKeys(s) << endl;


}