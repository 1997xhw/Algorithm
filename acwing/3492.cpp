#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 200010;
int n, m;
int s[N];
priority_queue<PII, vector<PII>, greater<PII> >q[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &s[i]);
	while(m --) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		
		while(q[b].size() && q[b].top().first <= a) {
			s[b] += q[b].top().second;
			q[b].pop();
		}
		
		if(s[b] < d) puts("-1");
		else {
			q[b].push({a + c, d});
			s[b] -= d;
			printf("%d\n", s[b]);
		}
	}	
	
	
	
	return 0;
}
