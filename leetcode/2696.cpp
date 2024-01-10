//
// Created by 徐浩闻 on 2024/1/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minLength(string s) {
        string st = "";
        st += s[0];
        s = s.substr(1, s.length() - 1);
        while (s.length() > 0) {
            if (st.length() > 0) {
                string tmp = "";
                tmp += st[st.length() - 1];
                tmp += s[0];
                if (tmp == "AB" || tmp == "CD") {
                    st = st.substr(0, st.length()-1);
                    s = s.substr(1, s.length() - 1);
                } else {
                    st += s[0];
                    s = s.substr(1, s.length() - 1);
                }
            } else {
                st += s[0];
                s = s.substr(1, s.length() - 1);
            }
        }
        return st.length();
    }
};

int main() {
    string  s = "ACBBD";
    Solution ss;
    cout << ss.minLength(s);

}