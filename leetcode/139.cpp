#include<bits/stdc++.h>
using namespace std;


/**
    集合表示：dp[i]表示长度为i个字符，用wordDict拼接出的集合
    属性：能否拼接出s的前i个字符
    状态转移：最后一个变化的部分，
        对于s的前i个字符ch，若ch[j, i]可由wordDict中的某个字符串组成，
            则 dp[i] = dp[j]; 此时能否拼成前i个字符由dp[j]决定。
        若不能，则跳过
**/

bool wordBreak(string s, vector<string>& wordDict) {
	bool dp[305] = {0};
	dp[0] = 1;
	for ( int i  = 1; i < s.size() + 1; i++) {
		for(auto j : wordDict) {
			int len = j.size();
			if ( i - len >= 0 && s.substr(i - len, len) == j && dp[i - len])
				dp[i] = true;
		}
	}
	return dp[s.size()];
}

int main() {
	string s = "catsandog";
	vector<string> word = {"cats","dog","sand","and","cat"};
	cout << wordBreak(s, word);
	return 0;
}