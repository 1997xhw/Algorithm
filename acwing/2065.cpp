#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int main() {
	scanf("%ld", &n);
	while(n) {
		printf("%ld ", n);
		n /= 2;
	}
	return 0;
}
