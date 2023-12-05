#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
typedef pair<double, double> PII;
typedef pair<int, int> PIII;
int n, d;
bool cmp(const pair<double, double>& a, const pair<double, double>& b) {
	return a.second < b.second;
}
int main() {
	cin >> n >> d;
	vector<PII> h;
	bool ok = true;
	for (int i = 0; i < n; i ++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (y > d) {
			ok = false;
		}
		h.push_back({x - sqrt(d * d - y * y), x + sqrt(d * d - y * y)});
	}
	if (!ok) {
	    cout << -1 << endl;
	    return 0;
	    
	}
	sort(h.begin(), h.end(), cmp);

	int res = 0;
	double tmp = -1e20;
	for (int i = 0; i < n; i ++) {
		if (tmp < h[i].first)
		{
			tmp = h[i].second;
			res ++;
		}
	}
	cout << res << endl;

	return 0;
}
