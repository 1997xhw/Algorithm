#include<bits/stdc++.h>
using namespace std;


int n1, n2;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

bool find( int x) {
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			st[j] = true;
			if( match[j] == 0 || find(match[j])) {
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int res = 0;
	for (int i = 1; i <= n1; i ++) {
		memset(st, false, sizeof st);
		if( find(i)) res ++; 
	}
	
}
