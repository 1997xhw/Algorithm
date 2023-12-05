#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin>>n;
	n/=1000;
	long long h=0,m=0,s=0;
	h=n/60/60%24;
	m=n/60%60;
	s=n%60;
	if(h<10)cout<<'0';
	cout<<h<<':';
	if(m<10)cout<<'0';
	cout<<m<<':';
	if(s<10)cout<<'0';
	cout<<s;
}
