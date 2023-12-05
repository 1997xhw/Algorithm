#include<bits/stdc++.h>
using namespace std;


int numDecodings(string s) {
	int n = s.size();
	int mod = 1e9 + 7;
	s = "00"+s;
	long long dp[100010] = {0};
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i < n+2; i++) {
		if(s[i] == '*' && s[i - 1] == '*') {
			dp[i] = dp[i - 2] * 15 + dp[i - 1] * 9;
		} else if (s[i] == '*' && s[i - 1] != '*') {
			int b = s[i - 1] - '0';
			dp[i] = dp[i - 1] * 9;
			if(b == 1) dp[i] += dp[i - 2] * 9;
			if(b == 2) dp[i] += dp[i - 2] * 6;
		} else if (s[i] != '*' && s[i - 1] == '*') {
			int a =  s[i] - '0';
			if(!a) dp[i] = dp[i - 2] * 2;
			else if (1 <= a && a <= 6) dp[i] = dp[i - 2] * 2 + dp[i - 1];
			else if (a > 6) dp[i] = dp[i - 2] + dp[i - 1];
		} else {
			int a = s[i] - '0', b = (s[i - 1] - '0') * 10 + a;
			if (1 <= a && a <= 9) dp[i] = dp[i - 1];
			if (10 <= b && b <= 26) dp[i] += dp[i - 2];
		}
		dp[i] %= mod;
		
	}
	return (int)dp[n + 1];

}
int main() {
	


	return 1;
}