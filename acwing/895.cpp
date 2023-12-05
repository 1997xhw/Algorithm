#include<bits/stdc++.h>
using namespace std;
int N;
int num[1005], res[1005];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i ++)
		cin >> num[i]; 
	
	for (int i = 1; i <= N; i ++) {
		res[i] = 1;
		for (int j = 1; j < i; j ++) {
			if(num[j] < num[i]) {
				res[i] = max(res[i], res[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i ++) ans = max(ans, res[i]);
	cout << ans;
	
	return 0;
	
}
