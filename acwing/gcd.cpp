#include<bits/stdc++.h>
using namespace std;
int n;
int f[100005];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;  
}
int main() {
	cout << gcd(40, 4);
	
	return 0;
}
