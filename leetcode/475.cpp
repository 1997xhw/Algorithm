#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& houses, vector<int>& heaters, int raduis) {
	int i = 0, j = 0;
	for (;i < houses.size(); i++) {
		while(j < heaters.size() && (houses[i] > heaters[j] + raduis)) {
			j++;
		}
		if(j < heaters.size() && (houses[i] >= heaters[j] - raduis) && (houses[i] <= heaters[j] + raduis)) continue;
		return false;
	}
	return true;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
	int ll = 0;
	int rr = 1e9;
	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());
	while(ll < rr) {
		int mid = ll + rr >> 1;
		if(check(houses, heaters, mid)) rr = mid;
		else ll = mid + 1;
	}
	return ll;

}



int main() {
	vector<int> houses = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
	vector<int> heaters = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
	cout << findRadius(houses, heaters);
}