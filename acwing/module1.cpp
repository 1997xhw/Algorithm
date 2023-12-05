#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
	for ( int i = 2; i <= n / i; i ++) 
		if (n % i == 0 )
			return false;
	return true;
}
void divide(int x) {
	for (int i = 0; i < x / i; i ++) {
		if (x % i == 0) {
			int s = 0;
			while(x % i == 0) x / = i, s ++;
			cout << i << " " << s << endl;
		} 
	}
	if (x > 1) cout << x << ' ' << 1 << endl;
	cout << endl;  
}

int primes[N], cnt; //primes[]´æ´¢ËùÓÐËØÊý 
bool st[N];//st[x]´æ´¢xÊÇ·ñ±»É¸µô   
void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for (j = 0; primes[j] <= n / i; j  ++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}
int main() {
	
	int test = 0;
//	cin >> test;
	for (int i = 0; i < 100; i++) {
		if(is_prime(i)) cout << i << endl;
	}
//	cout << is_prime(test);
	
	
	
}
