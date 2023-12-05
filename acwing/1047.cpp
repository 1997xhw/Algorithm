#include<bits/stdc++.h>
using namespace std;
int N, K;
int f[105], ff[105][105];
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i ++) scanf("%d", &f[i]);
	memset(ff, -0x3f, sizeof ff); 
	ff[0][0] = 0;
	for (int i = 1; i <= N; i ++) {
		for (int j = 0; j < K; j ++) {
			ff[i][j] = max(ff[i - 1][j], ff[i - 1][(j + K - f[i] % K) % K] + f[i]);
		}
	}
	printf("%d", ff[N][0]);
	
	return 0;
} 
