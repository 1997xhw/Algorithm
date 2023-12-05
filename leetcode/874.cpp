#include<bits/stdc++.h>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int x = 0, y = 0, dir = 0;
	//障碍物集合
	unordered_map<int, unordered_set<int>> obs;
	for( auto& iter : obstacles)
		obs[iter[0]].insert(iter[1]);

	int ans = 0;
	for (auto& cmd : commands) {
		if(cmd == -1) {
			dir = (dir + 1) % 4;
		} else if(cmd == -2) {
			dir = (dir + 4 - 1) % 4;
		} else {
			for (int i = 0; i < cmd; ++i) {
				auto iter = obs.find(x + dx[dir]);
				if(iter == obs.end() || iter -> second.find(y + dy[dir]) == iter -> second.end()) {
					x = x + dx[dir];
					y = y + dy[dir];
					ans = max(ans, x * x + y * y);
				}
			}
		}
	}
	return ans;
}
int main() {




}