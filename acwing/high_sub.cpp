#include<bits/stdc++.h>
using namespace std;

vector <int> sub(vector<int> &A, vector<int> &B) {
	vector <int> c;
	int t;
	for (int i = 0, t = 0; i < A.size(); i++) {
		t = A[i] - t;
		if(i < B.size()) t-= B[i];
		c.push_back((t + 10) % 10);
		if(t < 0) t = 1;
		else t = 0;
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}


int main() {




	return 1;
}