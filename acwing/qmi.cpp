#include<bits/stdc++.h>
using namespace std;

int qmi(int m, int k, int p) {
	int res = 1 % p, t = m;
	while(k) {
		if (k & 1) res = res * t % p;
		t = t * t % p;
		k >> 1;
	}
	return res;
}

int main() {
	return 0;
} 
