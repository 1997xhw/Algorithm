//
// Created by 徐浩闻 on 2023/12/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int res = 0;
        stack<char> st;
        for (auto &d: directions) {
            if (st.empty() && d == 'L') continue;
            else if (st.empty()) st.push(d);
            else if (!st.empty()) {
                if (d == 'L') {
                    if (st.top() == 'S')res += 1;
                    if(st.top()=='R') {
                        st.pop();
                        while(!st.empty()) {
                            if(st.top()=='R') res+=1;
                            st.pop();
                        }
                        st.push('S');
                        res+=2;
                    }
                }
                if(d=='S') {
                    while(!st.empty()) {
                        if(st.top()=='R') res+=1;
                        st.pop();
                    }
                    st.push('S');
                }
                if (d=='R') st.push('R');
            }
        }
        return res;
    }
};

int main() {
    string s = "SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR";
    Solution ss;
    cout << ss.countCollisions(s);
}