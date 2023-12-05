#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int mid;
bool check(string s1, string s2, int mid) {
	string s3 = "";
	for (int i = 0; i < mid; i++)
	s3 += s2;
	return s1.find(s3)!=string::npos;
	
}

int maxRepeating(string sequence, string word) {
	int l = 0;
	int r = floor(sequence.size()/word.size());           
    while( l < r) {
    	mid = ceil((l + r + 1)/2);
    	if(check(sequence, word, mid)) l = mid;
    	else r = mid - 1;
	}
	return l;
	
}

int main() {
	cin >> s1 >> s2;
	cout << maxRepeating(s1, s2);
	
	
	
	return 0;
}