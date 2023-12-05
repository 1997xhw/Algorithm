#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m = 1;
	string s;
	cin >> n >> s;
	
	vector<int> a(n, 1);
	for (int i = 0; i < n-1; i++) {
		if(s[i] == '<') a[i+1] = a[i] + 1;
		else if(s[i] == '=') a[i+1] = a[i];
	}
	for (int i = n - 2; i >=0; i--) {
		if(s[i] == '>') a[i] = max(a[i], a[i + 1] + 1);
		else if(s[i] == '=') a[i] = a[i + 1];
	}
	
	for (const int& ai : a) {
        cout << ai << ' ';
    }
	
}