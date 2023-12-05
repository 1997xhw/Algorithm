#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Node {
	int ts, id;
	bool operator< (const Node &t) const{
		return ts < t.ts;
	}
} hot[N];
int k, n, d;
int cnt[N];
bool sh[N];//每个帖子是否是热帖
int main () {
	cin >> n >> d >> k;
	for (int i = 0; i < n; i ++) {
		scanf("%d%d", &hot[i].ts, &hot[i].id);
	}
	sort(hot, hot + n);
	for (int i = 0, j = 0; i < n; i ++) {
		int id = hot[i].id;
		cnt[id] ++;

		while(hot[i].ts - hot[j].ts >= d) {
			cnt[hot[j].id] --;
			j ++;
		}
		if (cnt[id] >=k ) sh[id] = true;

	}
	for (int i = 0; i <= N; i ++)
		if (sh[i]) printf("%d\n", i);
	return 0;
}
