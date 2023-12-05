#include<bits/stdc++.h>

using namespace std;
int n, q, x;
int ll[100005];
bool check(int x) {
		
}

int bsearch_l(int l, int r, int aim) {
	while( l < r) {
		int mid = l + r >> 1;
		if(ll[mid] >= aim) r = mid;
		else  l = mid + 1; 
	}
	if (l > n - 1) return -1;
	return l;
}

int bsearch_r(int l, int r, int aim) {
	while(l < r) {
		int mid = l + r + 1>> 1;
		if(ll[mid] <= aim) l = mid;
		else r = mid - 1;
	}
	if (l > n - 1) return -1;
	return l;
}
int main() {
	cin >> n >> q; 
	for (int i = 0; i < n; i ++) {
		cin >> ll[i];
	}
	for (int i = 0; i < q; i ++) {
		cin >> x;
		int l = bsearch_l(0, n - 1, x);
		int r = bsearch_r(0, n - 1, x);
		if(ll[l] != x ) cout << "-1 -1" << endl;
		else
			cout << l << " " << r << endl;
	}
	
	
	
}
