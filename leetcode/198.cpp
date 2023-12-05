#include<bits/stdc++.h>
using namespace std;
int N = 110;
int rob(vector<int>& nums) {
	if(nums.size()<3){
		if(nums.size()==2) {
			return max(nums[0], nums[1]);
		} else return nums[0];
	}
	int d[N] = {0};
	d[0] = nums[0];
	d[1] = nums[1];
	for (int i = 2; i < nums.size(); i ++) {
		d[i] = max(d[i-1], d[i-2]+ nums[i]);
		if(d[i] == d[i-2]+ nums[i]) d[i-1] = max(d[i-2], d[i-1]);
	}
	return d[nums.size()-1];
    }


int main() {
	vector<int> h = {1,2,1,1};
 	cout << rob(h) << endl;
	
	
	
}
