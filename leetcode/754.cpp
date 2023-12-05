#include<bits/stdc++.h>

using namespace std;


int reachNumber(int target) {
	int sum = 0;
	int i = 0 , flag = 0;
	if(target < 0) {
		flag = 1;
		target *= -1;
	}
	while( sum < target) {
		i++;
		sum +=i;
	}
	if(sum == target) return i;
	while((sum - target) % 2 != 0) {
		i++;
		sum += i;
	}
	return i;
    
	
}
	
int main() {
	int t;
	cin >> t;
	cout << reachNumber(t);
	
	
	
return 1;
}