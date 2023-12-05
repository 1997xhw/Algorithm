#include<bits/stdc++.h>
using namespace std;

string s;
void ps(char c, int n) {
	while(n) {
		cout << c;
		n--;
	} 
}
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		auto c = s[i];
		if (s[i + 1] > '1' && s[i + 1] <= '9') ps(c, s[i + 1] - '0'), i ++;
		else cout << c; 
	}
	
	return 0; 
}
