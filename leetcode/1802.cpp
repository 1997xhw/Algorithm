#include<bits/stdc++.h>
using namespace std;


bool check(int n, int index, int maxSum, int mid) {
	int tempSum = mid, tt = mid;
	for(int i = index - 1; i >=0; i--) {
		if(tt != 1) tempSum+=(--tt);
		else {
			tempSum+= (i+1);
			break;
		}
		if(tempSum >maxSum) return false;
	}
	if(tempSum >maxSum) return false;
	tt = mid;
	for(int i = index + 1; i < n; i++) {
		if(tt != 1) tempSum+=(--tt);
		else {
			tempSum+= (n - i);
			break;
		}
		cout << tt << endl;
		if(tempSum >maxSum) return false;
	}
	cout << "tempSum:" << tempSum << endl;
	if(tempSum >maxSum) return false;
	return true;
}

int maxValue(int n, int index, int maxSum) {
	int ll = 1, rr = maxSum - n + 1;
	while(ll < rr) {
		int mid = ll + rr + 1 >> 1;
		cout << "mid: " << mid << endl;
		if(check(n, index, maxSum, mid)) ll = mid;
		else rr = mid - 1;
	}
	return ll;
}

int main() {
	int n, index, maxSum;
	cin >> n >> index >> maxSum;
	cout << maxValue(n, index, maxSum);
}