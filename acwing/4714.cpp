#include<bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    string s ;
    cin >> s;
    int len  = s.size();
    int map[10000] = {0};
    for(auto i : s) {
        map[int(i)]++;
    	cout << int(i) << endl;
    }
    
    for(auto i : s) {
        ans+=map[int(i)];
    }
    cout << ans;
    

}