#include<bits/stdc++.h>

using namespace std;

bool parseBoolExpr(string expression) {
	stack<char> s;
	for(char e : expression) {
		if(e != ',' && e != ')') {
			s.push(e);
		} else if (e == ')') {
			int t = 0, f = 0;
			while(s.top() != '(') {
				auto ss = s.top();
				if (ss == 't') t++;
				else f++;
				s.pop();
			}
			s.pop(); 	//pop'('
			char op = s.top();
			s.pop();	//pop'操作符'
			
			if (op == '!') {
				s.push(t > f ? 'f' : 't');
			} else if( op =='|') {
				s.push(t ? 't' : 'f');
			} else if( op == '&') {
				s.push(f ? 'f' : 't');
			}
					
		} else continue;
	}
	return s.top() == 't' ? true : false;
}
int main() {
	cout << parseBoolExpr("|(&(t,f,t),!(t))");


	return 0;
}