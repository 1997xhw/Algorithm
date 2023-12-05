#include<bits/stdc++.h>
using namespace std;


vector<int> mul(vector<int> &A, int b) {
	vector<int> c;
	
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {
		if(i < A.size()) t += A[i] *b;
		c.push_back(t % 10);
		t /= 10;
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
	
	return c;
}

int main() {
	
	
	
	
	return 0;
}