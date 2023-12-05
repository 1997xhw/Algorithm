#include <bits/stdc++.h>
using namespace std;


vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	int l = 0, r = arr.size() - k;
	int ff = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(mid + k < arr.size() && x - arr[mid] > arr[mid + k] -x) l = mid  + 1;
		else r = mid - 1;
	}
	vector<int> ans;
	for ( int i = l; i < l + k; i++) {
		ans.push_back(arr[i]);
	}
	return ans;


}
int main () {

	vector<int> arr = {1,1,1,10,10,10};
	vector<int> ans;
	ans = findClosestElements(arr, 1, 9);
	for (auto i : ans) cout << i << " ";


}