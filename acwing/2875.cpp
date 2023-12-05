#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

stack<LL> s;
int main() {
	int n;
	LL res = 0;
	cin >> n;
	while(n --) {
		int x;
		scanf("%d", &x);
		if (s.empty()) {
			s.push(x);
			continue;
		}
		while(!s.empty()) {
			if (s.top() <= x) {
				LL tt = s.top();
				res += tt * x;
				s.pop();
				x = tt + x;
			}else {
				break;
			}
		}
		s.push(x);

	}
	while(s.size() > 1) {
		LL a = s.top();
		s.pop();
		LL b = s.top();
		s.pop();
		res += a * b;
		s.push(a + b);
	}

	cout << res << endl;
	return 0;
}

