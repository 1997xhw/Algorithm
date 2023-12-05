#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main() {
	int n = 4;
	while(n) {
		cout << n&1;
		n >> 1;
	}
	
	return 0;
}
