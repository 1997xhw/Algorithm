#include<bits/stdc++.h>
using namespace std;
int N = 110;
int robb(vector<int>& nums, int a, int b) {
	int d[N] = {0};
	d[a] = nums[a];
	d[a+1] = nums[a+1];
	for (int i = a+2; i < b; i ++) {
		d[i] = max(d[i-1], d[i-2]+ nums[i]);
		if(d[i] == d[i-2]+ nums[i]) d[i-1] = max(d[i-2], d[i-1]);
	}
	if(b == nums.size())
		return d[nums.size()-1];
	else return d[nums.size()-2];

}
int rob(vector<int>& nums) {
	if(nums.size() < 4) {
		if(nums.size()==3) return max(nums[0], max(nums[1], nums[2]));
		else if(nums.size()==2) return max(nums[0], nums[1]);
		else return nums[0];
	}
	vector<int>::const_iterator First = nums.begin();
	vector<int>::const_iterator Second = nums.end();

	return max(robb(nums, 0, nums.size()-1), robb(nums, 1, nums.size()));

}




int main() {
	vector<int> h = {1,2,3,1};
	cout << rob(h) << endl;



}
