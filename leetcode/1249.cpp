//
// Created by 徐浩闻 on 2024/2/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans = "";
        int len = s.length();
        int right = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == ')')
            right++;
        }
        int left = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                if (right > 0){
                    ans += '(';
                    left++;
                    right--;
                }

            } else if (s[i] == ')') {
                if (left > 0) {
                    ans += ')';
                    left--;
                } else if (left == 0) right--;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.minRemoveToMakeValid(")))((");

}