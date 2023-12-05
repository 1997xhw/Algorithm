#include<bits/stdc++.h>
using namespace std;

int findLUSlength(vector<string>& strs) {
	auto is_subseq = [](const string&s, const string& t) -> bool {
		int l = 0, r = 0;
		while(l < s.size() && r < t.size()) {
			if(s[l] == t[r]) ++l;
			++r;
		}
		return l == s.size();
	};
	
	int n = strs.size();
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		bool check = true;
		for (int j = 0; j < n; j++) {
			if(i != j && is_subseq(strs[i], strs[j])) {
				check = false;
				break;
			} 
		}
		if(check) {
			ans = max(ans, (int)strs[i].size());
		}
	}
	return ans;	
}


int main () {




}