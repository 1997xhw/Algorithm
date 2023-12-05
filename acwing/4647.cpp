#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, x;
int H[N];


bool check(int u) {
	for (int i = 1 + u; i <= n; i ++) {
		if (H[i - 1] - H[i - u - 1] < 2*x) return false;
	}
	return true;
}

int main() {
	cin >> n >> x;
	H[0] = 0;
	for (int i = 1; i < n; i ++) {
		cin >> H[i];
		H[i] = H[i] + H[i - 1];
	}
	int l = 1, r = n;
	while( l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;

	return 0;
}
