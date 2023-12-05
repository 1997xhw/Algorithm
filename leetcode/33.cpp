#include<bits/stdc++.h>
using namespace std;

int low_bound(vector<int>& nums, int target, int ll, int rr) {
	int r = rr;
	while(ll + 1 < r) {
		int mid = ll + (r - ll >> 1);
		if(nums[mid] < target) ll = mid;
		else r = mid;
	}
	return r < rr && nums[r] == target ? r : -1;
}
int search(vector<int>& nums, int target) {
	//找到分割点
	int ll = -1, rr = nums.size()-1;
	while(ll + 1 < rr) {
		int mid = ll + (rr - ll >> 1);
		if(nums[mid] > nums.back()) ll = mid;
		else rr = mid;
	}
	//确定是在左段还是在右端
	int ff = rr;
	if(target > nums.back()) return low_bound(nums, target, -1, ff);
	else return low_bound(nums, target, ff - 1, nums.size());
	
}
int main() {

vector<int> nums = {4,5,6,7,0,1,2};
cout << search(nums, 0);

}