#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
	int m = str1.size(), n = str2.size();
	str1 = " " + str1;
	str2 = " " + str2;
	vector<vector<int>> dp(m+1, vector<int>(n + 1, 0));
	for (int i = 1; i <=m; i++ ) {
		for (int j = 1; j <= n; j++) {
			if(str1[i] == str2[j]) dp[i][j] == dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int i = m, j = n ;
	string ans;
	while(i > 0 || j > 0) {
		if(i == 0) ans += str2[j--];
		else if(j == 0) ans += str1[i--];
		else {
			if (str1[i ] == str2[j]) {
				ans += str1[i];
				i--;
				j--;
			} else if (dp[i][j] == dp[i - 1][j]) ans += str1[i--];
			else ans += str2[j--];
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}


int main () {
	cout << shortestCommonSupersequence("abac", "cab");


}