#include<bits/stdc++.h>
using namespace std;
const int N = 10010, M = 1000010;
int n, m;
//char s[M], p[N];
string s, p;
int ne[N];

//5
//ababaaab
//1
//a

int kmp() { 
	s = s + " ";
	p = p + " "; 
	//next数组 
	for (int i = 2, j = 0; i <= m; i ++) {
		while(j && p[j + 1] != p[i]) j = ne[j];
		if( p[i] == p[j + 1]) j ++;
		ne[i] = j;
	}
	
	for (int i = 1, j = 0; i <= n; i++) {
		while(j && s[i] != p[j + 1]) j = ne[j];
		if( s[i] == p[j + 1]) j++;
		if(j ==  m) {
			j = ne[j];
			//匹配成功 
		}
	}	
} 


int main() {
	//s 长文本
	//p 模式串 
	cin >> p >> m;
//	s = " " + s;
//	p = " " + p;

	for (int i = 2, j = 0; i <= m; i++) {
		while(j && p[i] != p[j + 1]) j = ne[j];
		if(p[i] == p[j + 1]) j++;
		ne[i] = j;
	}
	
	for (int i = 0; i < m; i++) {
		cout << ne[i];
	} 
//	for (int i = 1, j = 0; i <= n; i++) {
//		while(j && s[i] != p[j + 1]) j = ne[j];
//		if(s[i] == p[j + 1]) j++;
//		if(j == m) {
//			printf("%d ", i - m);
//			j = ne[j];
//		}
//	}



}
