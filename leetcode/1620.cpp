#include <bits/stdc++.h>
using namespace std;


float dis(vector<int> t1, vector<int> t2) {
	return (sqrt(pow(t1[0] - t2[0], 2) + pow(t1[1] - t2[1], 2)));
}


vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
	int ans = 0;
	vector<int> anss = {0, 0};
	float d;
	for (int i = 0; i <= 50; i++) {
		for( int j = 0; j <= 50; j++) {
			vector<int> t = {i, j};
			int tempp = 0;
			for(int k = 0; k < towers.size(); k++) {
				d = dis(towers[k], t);
				if(towers[k][2] && d <= radius) {
					tempp += floor(towers[k][2]/(1+d));//注意向下取整
				}
			}
			if(tempp > ans) {
				anss[0] = i;
				anss[1] = j;
				ans = tempp;
			}

		}

	}
	return anss;
}





int main() {
	vector<int> t1 = {42, 0, 0};
	vector<int> t2 = {2, 1, 7};
	vector<int> t3 = {0, 1, 9};
	vector<vector<int>> ttt = {t1};
//	cout << dis(t1, t2);
	vector<int> tttt = bestCoordinate(ttt, 2);
	cout << tttt[0] << " " << tttt[1] << endl;

}