#include<bits/stdc++.h>
using namespace std;

int n;
int g[N][N];
int dist[N];
bool st[N];

int prim() {
	memset(dist, 0x3f, sizeof dist);
	
	int res = 0;
	for (int i = 0; i < n; i ++) {
		int t = -1;
		for (int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if (i && dist[t] == INF) return INF;
		
		if(i) res+= dist[t];
		st[t] = true;
		
		for (int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
	}
	return res; 
}

int main() {
	
	
	
	
	
}
