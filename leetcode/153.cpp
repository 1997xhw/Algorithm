#include<bits/stdc++.h> 
using namespace std;

int finMin(vector<int>& nums) {
	int ll = 0, rr = nums.size() - 1;
	while(ll  <=rr) {
		int mid = ll + (rr - ll >> 1);
		if(nums[mid] > nums.back()) ll = mid + 1;
		else rr = mid - 1;
	}
	return nums[rr + 1];	
}


int main () {
	vector<int> nums = {3, 4, 5, 1, 2};
	cout << finMin(nums);
}