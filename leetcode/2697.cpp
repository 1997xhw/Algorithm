//
// Created by 徐浩闻 on 2023/12/13.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for(int i =0, j = s.length()-1; i < j; ++i, --j) {
            s[i] = s[j] = min(s[i], s[j]);
        }
        return s;
    }
};

int main() {


}