#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &nums, int low, int high) {
	int ans = 0;
	unordered_map<int, int> cnt;
	for (int x: nums) ++cnt[x];
	for( ++high; high; high >>= 1, low >>= 1) {
		unordered_map<int, int> nxt;
		for( auto&[x, c] : cnt) {
			if(high % 2 && cnt.count(x ^ (high - 1))) ans += c * cnt[x ^ (high - 1)];
			if (low % 2 && cnt.count(x ^ (low - 1))) ans -= c * cnt[x ^ (low - 1)];
			nxt[x >> 1] += c;
			
		}
		cnt = move(nxt);
	}
	return ans / 2;
	
}

int main() {
	

}