#include<bits/stdc++.h>
using namespace std;

int getLucky(string s, int k) {
	string tmp = "";
	for (auto ss : s) {
//		cout << ss-'a' << " ";
		tmp += to_string(1 + ss-'a');
	}
	int ans = 0;
	cout << tmp << endl;
	while(k--) {
		ans = 0;
		for (auto tt : tmp) {
//			cout << tt << " ";
			ans+= (tt-'0');
		}
//		cout << endl;
		tmp = to_string(ans);
	}
	return ans;
}

int main() {
	cout << getLucky("leedasdsadsadfsafasfsadfgasdfasdfastcode", 3);
	
	
}