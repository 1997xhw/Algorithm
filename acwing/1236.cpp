#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;
int n;
int A[N], B[N], C[N], cnt[3][N], S[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> A[i];
		cnt[0][++A[i]] ++;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> B[i];
		cnt[1][++B[i]] ++; 
	}
	for (int i = 1; i <= n; i ++) {
		cin >> C[i];
		cnt[2][++C[i]] ++;
	}
	for (int i = 1; i < N; i ++) {
		cnt[0][i] += cnt[0][i - 1];
		cnt[2][i] += cnt[2][i - 1];
	}
	LL res = 0;
	for (int i = 1; i <= n; i ++) {
		res += (LL)cnt[0][B[i] - 1] * ( cnt[2][N - 1] - cnt[2][B[i]]);
	}
	cout << res << endl;
	return 0;
}
