#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		int t = i;
		bool ok = true;
		while(t) {
			int tt = t % 10;
			if(tt == 1 || tt == 2 || tt == 9 || tt == 0) {
				ok = false;
				break;
			}
			t /= 10;
		}
		if(!ok) res += i;
	}
	cout << res << endl;
	return 0;
}
