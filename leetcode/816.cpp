#include<bits/stdc++.h>
using namespace std;


string ff(int i ,int j, string s) {
	int len = s.size();
	vector<string> ans;
	
	
}

vector<string> ambiguousCoordinates(string s) {
	int len = s.size();
	vector<string> ans;
	
	auto f = [&](int i, int j) {
		vector<string> tmp;
		for (int k = 1; k <= j - i; k++) {
			string l = s.substr(i, k);
			string r = s.substr(i + k, j - i - k);
			if((l == "0" || l[0] != '0') && r.back() != '0') tmp.push_back(l+(k < j - i ?".":"") + r);//左半部不能以0开头，除非左半部分只有0；右半部不能以0结尾
		}
		return tmp;
		
	};
	
	for (int i = 2; i < len - 1; i++) {
		for(auto& x : f(1, i)) {
			for (auto& y : f(i, len - 1)) {
				ans.emplace_back("(" + x + ", " + y + ")");
			}
		}
	}
	return ans;
	
}

int main() {
	vector<string> ans;
	ans = ambiguousCoordinates("(100)");
	for( auto i : ans) {
		cout << i << endl;
	}

}