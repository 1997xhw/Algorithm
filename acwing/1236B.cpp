#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n;
int A[N], B[N], C[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> A[i];
	for (int i = 1; i <= n; i ++)
		cin >> B[i];
	for (int i = 1; i <= n; i ++)
		cin >> C[i];
	LL res = 0;
	sort(A + 1, A + n + 1);
	sort(C + 1, C + n + 1);
	for (int b = 1; b <= n; b ++) {
		int l = 1, r = n;
		while( l < r) {
			int mid = l + r + 1 >> 1;
			if(A[mid] < B[b])  l = mid;
			else r = mid - 1; 
		}
		int tempA = l;
		if(A[tempA] >= B[b]) tempA = 0;
		
		l = 1, r = n;
		while(l < r) {
			int mid = l + r >> 1;
			if(C[mid] > B[b]) r = mid;
			else l = mid + 1;
		}
		int tempC = l;
		if (B[b] >= C[n]) tempC = n + 1;
		res += (LL)tempA * (n - tempC + 1);
		
	}
	cout << res << endl;


	return 0;
}
