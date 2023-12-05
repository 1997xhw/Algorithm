#include<bits/stdc++.h>
using namespace std;
int getTime() {
	int h1,m1,s1,h2,m2,s2,d=0;
	scanf("%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
	int time=d*24*3600+h2*3600+m2*60+s2-(h1*3600+m1*60+s1);
	return time;

}
int main() {
	int t;
	cin >> t;
	while(t -- ) {
		int time1 = getTime();
		int time2 = getTime();
		int ans = time1 + time2 >> 1;
		printf("%02d:%02d:%02d\n", ans/3600, ans/60%60, ans%60);
	}
	return 0;
}
