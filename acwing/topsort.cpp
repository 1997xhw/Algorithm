#include<bits/stdc++.h>
using namespace std;

const int N 100005;
int h[N], e[N], ne[N], idx;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
	st[u] = true;//st[u]表示点u已经被遍历过

	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) dfs[j];
	}
}

bool topsort() {
	int hh = 0, tt = -1;
	
	//d[i]存储点i的入度
	for (int i = 1; i <= n; i++) {
		if(!d[i])
			q[++ tt] = i;
	}
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; i!= -1; i = ne[i]) {
			int j = e[i];
			if (-- d[j] ==0)
				q[++ tt] = i
		}
	}
	// 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列 
	return tt == n - 1;
}

int main() {
	idx = 0;
	memset(h, -1, sizeof h);

	queue<int> q;
	st[1] = true;
	q.push(1);

	while(q.size()) {
		int t = q.front();
		q.pop();
		
		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(!st[j]) {
				st[j] = true;
				q.push(j);
			}
		}
	}
}
