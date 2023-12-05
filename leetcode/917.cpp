//
// Created by 徐浩闻 on 2023/11/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> ss(105, ' ');
        stack<char> sss;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
//                cout << i << '* ' << s[i] << endl;
                sss.push(s[i]);
            } else {
//                cout << i << ': ' << s[i] << endl;
                ss[i] = s[i];
            }
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (ss[i] != ' ') ans += ss[i];
            else {
                ans += sss.top();
                sss.pop();
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;

}