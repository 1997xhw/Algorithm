#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> up;
vector<vector<int>> ll;
int len;
bool check(int mid) {
	for (int i = mid; i + mid < len; i++) {
		for (int j = mid; j + mid < len; j++) {
			if((up[i + mid][j] >= 2 * mid + 1) && (ll[i][j + mid] >= 2 * mid + 1)) return true;
		}
	}
	return false;
}

int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
	if (mines.size() == n) return 0;
	vector<vector<int>> mp(n, vector<int>(n, 1));
	for (auto& m : mines) mp[m[0]][m[1]] = 0;
		
	up = ll = vector<vector<int>>(n, vector<int>(n, 1));
	
	//前缀和处理 行
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if(mp[i][j]) tmp++;
			else tmp = 0;
			ll[i][j] = tmp;
		}
	}
	//前缀和处理 列
	for (int j = 0; j < n; j++) {
		int tmp = 0;
		for (int i = 0; i < 0; i++) {
			if(mp[i][j]) tmp++;
			else tmp = 0;
			up[i][j] = tmp;
		}
	}
	
	len = n;
	int l = 0, r = (n - 1) >> 1;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l + 1;
	
	
}

int main() {





}