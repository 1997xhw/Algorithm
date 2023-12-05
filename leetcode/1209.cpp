#include<bits/stdc++.h>
using namespace std;
typedef pair<char, int> pp;
string removeDuplicates(string s, int k) {
	stack<pp> ss;
	for(auto i : s) {
		if(!ss.empty() && ss.top().first == i) {
			ss.top().second++;
//			cout << ss.top().first  << " " << ss.top().second<< endl;
		}else {
			ss.push(pp(i, 1));
		}
		if(ss.top().second == k) ss.pop();
	}
	string ans = "";
	while(!ss.empty()) {
		for(int i = 0; i < ss.top().second; i++)
		ans+=ss.top().first;
//		if(ss.top().second == 2) ans+=ss.top().first;
		ss.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main () {

	cout << removeDuplicates("deeffffc", 10000);

}