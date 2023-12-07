#include<bits/stdc++.h>
using namespace std;
const int N = 100003;
int p[N], size[N], d[N];


int find(int x) {
	if(p[x] != x) {
		int u = find(p[x]);
		d[x] += d[p[x]];
		p[x] = u;
		
	}
	return p[x];
}


int main() {
	int n;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
		size[i] = 1;
		d[i] = 0; 
	}
	

//	size[find(b)] += size[find(a)];
//	p[find(a)] = find[b];
//	d[find(a)] = distance;
	
	 


}
