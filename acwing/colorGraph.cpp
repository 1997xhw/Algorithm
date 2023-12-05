#include<bits/stdc++.h>
using namespace std;

int n;
int h[N], e[M], ne[M], idx;
int color[N];

bool dfs(int u, int c) {
	color[u] = c;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if ( color[j] == -1) {
			if (!dfs(j, !c)) return false;
		} 
		else if (color[j] == c) return false;
	}
	
	return true;
}
bool check() {
	memset(color, -1, sizeof color);
	bool flag = true;
	for (int i = 1; i <= n; i ++) {
		if (color[i] == -1) 
			if(!dfs(i, 0)) {
				flag = false;
				break;
			}
	}
	return flag;
}

int main() {
	
	
}
