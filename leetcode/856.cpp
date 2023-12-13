//
// Created by 徐浩闻 on 2023/12/12.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, d = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') d++;
            else {
                d--;
                if (s[i - 1] == '(') {
                    ans += (1 << d);
                }
            }
        }
        return ans;
    }
};

int main() {


}