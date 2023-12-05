#include<bits/stdc++.h>
using namespace std;

int low_bound(vector<int>& nums, int target) {
	int ll = 0, rr = nums.size();//左闭右开
	while(ll < rr) {
		int mid = ll + rr >> 1;
		if(nums[mid] < target) ll = mid + 1;
		else rr = mid;
	}	
	return ll;
}
vector<int> searchRange(vector<int>& nums, int target) {
	int begin = low_bound(nums, target);
	if(begin == nums.size() || nums[begin] != target) return vector<int>{-1, -1};
	int end = low_bound(nums, target + 1);
	return vector<int>{begin, end};
	
}

int main() {



}