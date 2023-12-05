#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int cnt[N];
struct shop {
	int ts, id;
	bool operator < (const shop& s) {
		return id < s.id || id == s.id && ts < s.ts;
	}
} s[N];
int main() {
	int n, m, t, ts, id;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < m; i ++) {
		scanf("%d %d", &s[i].ts, &s[i].id);
	}
	sort(s, s + m);
	int cur = 2, ans = 0;
	bool ok = false;
	for (int i = 1; i <= m; i ++) {
		if(s[i].id != s[i - 1].id) {
			if(ok && cur - (t - s[i - 1].ts) > 3) ans ++;
			ok = false;
			cur = 2;
		}
		else {
			int diff = s[i].ts - s[i - 1].ts - 1;
			if (diff == -1) diff = 0;
			cur = max(0, cur - diff);
			if (cur <= 3) ok = false;
			cur += 2;
			if(cur > 5) ok = true;
		}
	}

	cout << ans << endl;


	return 0;
}
