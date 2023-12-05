#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;
typedef long long LL;

int main() {
	LL x, y;
	cin >> x >> y;
	LL k = max(abs(x), abs(y));
	if(x >= y) cout << 4 * k * k + abs(x - k) + abs(y - k) << endl;
	else cout << 4 * k * k- abs(x - k) - abs(y - k) << endl;
	return 0;
}
