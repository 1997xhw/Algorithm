//
// Created by 徐浩闻 on 2024/2/3.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        int cnt = 1, len = pattern.length();
        string ans = "";
        for (int i = 0; i < len; i++) {
            if (pattern[i] == 'D') st.push(cnt);
            else if (pattern[i] == 'I') {
                ans += (cnt + '0');
                while ( !st.empty()) ans += (st.top() + '0'), st.pop();
            }
            cnt++;
        }
        ans += (cnt + '0');
        while (!st.empty()) ans += (st.top() + '0'), st.pop();
        return ans;
    }
};

int main() {
    string pattern = "IIIDIDDD";
    Solution s;
    cout << s.smallestNumber(pattern);

}