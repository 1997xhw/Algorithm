#include<bits/stdc++.h>

using namespace std;
int n;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

int spfa() {         
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	queue<int> q;
  	q.push(1);
	st[1] = true;
	
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		st[t] = false;
		
		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}


int main() {
	
	
	
	
}
