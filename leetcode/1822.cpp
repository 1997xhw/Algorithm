# include<iostream>
# include<vector>
# include<algorithm>

using namespace std;


int arraySign(vector<int>& nums) {
	int len  = nums.size();
	int ans = 1;
	for (int i = 0; i < len; i++) {
		if (!nums[i]) return 0;
		if(nums[i]<0) ans*=-1;
	}
	if (ans > 0) return 1;
	else if (ans == 0) return 0;
	else return -1;
}



int main() {
	vector <int> A1 = {1, -2, 3, 12, -3, 25, 9,-1};
	sort(A1.begin(), A1.end());
	for (int i = 0; i < A1.size(); i++){
		cout << A1[i] << endl;
	}
	
	
}