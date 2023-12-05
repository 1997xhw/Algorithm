#include<bits/stdc++.h>
using namespace std;

int n;
int ants[55];

//初始状态下
//ants[0]右边的蚂蚁且往左走的蚂蚁会被传染 会被传染 
//ants[0]左边的蚂蚁往右走的蚂蚁   
//								同时在x[0]蚂蚁右边存在往左走的蚂蚁 则会被传染 
int main () {
	memset(ants, 0, sizeof ants);
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> ants[i];
	}
	int left = 0, right = 0;
	int x = ants[0];
	for (int i = 1; i < n; i ++) {
		if(abs(x) < abs(ants[i]) && ants[i] < 0) right++;
		else if(abs(x) > abs(ants[i]) && ants[i] > 0) left++;
	} 
	if(x > 0){
		if(right > 0)
			cout << right + left + 1;
		else
			cout << 1;
	} 
	else if(x < 0) {
		if(left > 0)
			cout << right + left + 1;
		else
			cout << 1;
	}
	 
}
