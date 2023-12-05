#include<bits/stdc++.h>
using namespace std;

    int minimumSize(vector<int>& nums, int op) {
        int i, m, l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) / 2;
            for (i = m = 0; i < nums.size(); i++) m += (nums[i] - 1) / mid;
            if (m <= op) r = mid;
            else l = mid + 1;
        }
        return r;
    }

bool check(int l, int r, vector<int>& nums) {
	
}
int main() {




	return 0;
}