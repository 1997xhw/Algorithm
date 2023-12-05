#include<bits/stdc++.h>

using namespace std;

const int N = 100100;
int n, m, maxx;
int cow[N] = {0};
double sum[N];

bool check(double avg) {
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + cow[i] - avg;//前缀和 与平均值的差值
	}
	double minv = 0;
	for (int i = 0, j = m; j <= n; i++, j++) {
		minv = min(minv, sum[i]);
		if( sum[j] - minv >= 0) return true;//平均值估小了
	}
	return false;//平均值估大了


}

int main() {
	scanf("%d %d", &n, &m);
	double l, r = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cow[i]);
		r = max(r, (double)cow[i]);
	}

	while(r - l > 1e-5) {
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;//找左边界
		else r = mid;
	}
	printf("%d\n", (int)(r*1000));

	return 0;
}