#include<bits/stdc++.h>
using namespace std;


vector<string> ans;
string k = " ";
int n;
void dfs(int index, string &s, string w, vector<string>& wordDict) {
	if(index == n) {
		ans.push_back(w);
		return ;
		
	}
	if (index != 0) w += " ";
	string x;
	for (int i = index; i < n && i <= index + 10; i++) {
		x += s[i];
		if(find(wordDict.begin(), wordDict.end(), x) != wordDict.end()) {
			dfs(i+1, s, w + x, wordDict);
		}
	}
}



vector<string> wordBreak(string s, vector<string>& wordDict) {
	string w;
	n = s.size();
	dfs(0, s, w, wordDict);
	return ans;

}
int main() {
	
	vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
	vector<string> ans = wordBreak("catsanddog", wordDict);
	for (auto i : ans) {
		cout << i << endl;
	}

	return 1;
}