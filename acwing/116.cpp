#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
const int N = 5;
char g[N][N], backup[N][N];

int get(int x, int y) {
	return x * 4 + y;
}

void turn_one(int x, int y) {
	if(g[x][y] == '+') g[x][y] = '-';
	else g[x][y] = '+';
}
void turn_all(int x, int y) {
	for (int i = 0; i < 4; i++){
		turn_one(x, i);
		turn_one(i, y);
	}
	turn_one(x, y);
}


int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> g[i][j];	
		}
	}
	vector<PII> res;
	for (int op = 0; op < 1 << 16; op ++) {
		vector<PII> temp;
		memcpy(backup, g, sizeof g);
		
		for (int i = 0; i < 4; i ++) {
			for (int j = 0; j < 4; j++) {
				if(op >> get(i, j) & 1) {
					temp.push_back({i, j});
					turn_all(i, j);
				}
			}
		}
		
		bool ok = false;
		for (int i = 0; i < 4; i ++) {
			for (int j = 0; j < 4; j++) {
				if(g[i][j] == '+') ok = true;
			}
		}
		if(!ok && (res.empty() || res.size() > temp.size()))
		res = temp;
		memcpy(g, backup, sizeof g);
		
	}
	cout << res.size() << endl;
	for (auto op : res) cout << op.x + 1 << " " << op.y + 1 << endl;
	return 0;
	
	
}
