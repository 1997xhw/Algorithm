#include<bits/stdc++.h>
using namespace std;
int w, m, n;

int main() {
	cin >> w >> m >> n;
	m--;
	n--;
	int x1 = m / w;
	int x2 = n / w;
	int y1 = (x1 % 2) == 1 ? ((w - 1) - (m % w)) : (m % w);
	int y2 = (x2 % 2) == 1 ? ((w - 1) - (n % w)) : (n % w);
	cout << (abs(x1 - x2) + abs(y1 - y2));
}  
