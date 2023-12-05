#include<bits/stdc++.h>
using namespace std;


int main() {
    int n = 5, res = 0;
    while(n --) {
        string x;
        cin >> x;
        if(x[0] == x[2] && x[3] - x[1] == 1) res ++;
    }
    cout << res << endl;
    
    
    
    return 0;
}
