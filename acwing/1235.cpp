#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n;
int a[N];
  
int main() {
	 long double s;
	 scanf("%d%Lf", &n, &s);
	 for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	 sort(a, a + n);
	 
	 long double res = 0, avg = s / n; 
	 for (int i = 0; i < n; i ++) {
	 	long double cur = s / (n - i);
	 	if (a[i] < cur) cur = a[i];
	 	res += (cur - avg) * (cur - avg);
	 	s -= cur;
	 }
	printf("%.4Lf", sqrt(res / n));
	
	
	return 0;
}
