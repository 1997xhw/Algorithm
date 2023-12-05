#include<bits/stdc++.h>
using namespace std;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	int a, b, c;
	scanf("%d/%d/%d", &a, &b, &c);
	for (int i = 19600101; i <= 20591231; i++) {
		int y = i / 10000, m = i % 10000 / 100, d = i % 100;
		if (m == 0 || m > 12) continue;
		if (d == 0) continue;
		if (m != 2) {
			if (d > days[m]) continue;
		} else {
			int leap = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
			if (d > days[m] + leap) continue;
		}
		if ((y % 100 == a && m == b && d == c) ||  // 年/月/日
		        (m == a && d == b && y % 100 == c) ||  // 月/日/年
		        (d == a && m == b && y % 100 == c) )   //月/日/年
			printf("%d-%02d-%02d\n", y, m, d);  //补前导0

	}


	return 0;
}
