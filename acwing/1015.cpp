#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int T, R, C;
int F[105][105];
int K[105][105];
int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> R >> C;
		memset(F, 0, sizeof F);
		memset(K, 0, sizeof K);
		for (int j = 1; j <= R; j ++) 
			for (int k = 1; k <= C; k ++) 
				cin >> F[j][k];
		
	for (int j = 1; j <= R; j++)	
		for (int k = 1; k <= C; k ++)
			K[j][k] = max(K[j - 1][k], K[j][k - 1]) +F[j][k];
	cout << K[R][C] << endl;
		
	}
}
 
