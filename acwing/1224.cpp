#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n;
int bo[N];
bool st[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++)
	scanf("%d", &bo[i]);
	memset(st, true, sizeof st);
	int k = 0;
	for (int i =  1; i <= n; i ++) {
		if(st[i]) {
			k ++;
			for (int j = i; st[j]; j = bo[j]) {
				st[j] = false;
			}
		}
	}
	cout << n - k << endl;
	return 0;
}
