#include<bits/stdc++.h>
using namespace std;
const int N = 22;
int n, k;
int num[N];
void get_cnt(int n) {
	int cnt = 1;
	while(n) {
		if (n & 1) num[cnt] ++;
		cnt ++;
		n >>= 1;
	}
}
int main() {
	cin >> n;
	while( n --) {
		int sum = 0;
		memset(num, 0, sizeof num);
		scanf("%d", &k);
		for (int i = 0; i < k; i ++) {
			int s;
			scanf("%d", &s);
			get_cnt(s);
			sum ^= s;
		}
		if (sum == 0)	puts("0");
		else {
			for (int i = 20; i >= 1; i --) {
				if (num[i] == 1) {
					puts("1");
					break;
				}
				else if (num[i] & 1) {
					if (k % 2 == 0) {
						puts("-1"); break;
					}
					else {
						puts("1"); break;
					}
				}
			}
		}


	}

	return 0;
}
