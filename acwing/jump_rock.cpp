#include <iostream>
using namespace std;
const int N=50010;
int L,n,m;
int d[N];

bool check(int mid) {
	int cnt = 0, last = 0;
	for (int i = 1; i <= n; i++) {
		if(d[i] - last < mid) cnt++;
		else last = d[i];
	}
	return cnt <= m;
}


int main() {
	scanf("%d %d %d",&L,&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
	}
	n++;
	d[n] = L;//存入终点距离
	int l = 1,r = 1000000000;
	while(l < r) {
		int mid = (l + r + 1) >> 1;//二分查找右边界  因为查找的是 最大值 使用bssearchl
		if(check(mid))
			l = mid;
		else r = mid - 1;
	}
	printf("%d\n", r);
	return 0;
}