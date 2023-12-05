#include<bits/stdc++.h>
using namespace std;

string s1, s2;
bool check(string s1, string s2, int mid) {
	string s3 = "";
	for (int i = 0; i < mid)
	s3 += s2;
	if(s1.find(s3)) return true;
	else return false;
	
}

int maxRepeating(string sequence, string word) {
	int l = 0;
	int r = floor(strlen(sequence)/strlen(word));             
    while( l < r) {
    	int mid = ceil(l+r)/2;
    	
    	if(check(sequence, word, mid)) l = mid;
    	else r = mid;
	}
	return l;
	
}

int main() {
	cin >> s1 >> s2;
	cout << maxRepeating(s1, s2);
	
	
	
	return 0;
}