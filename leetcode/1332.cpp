//
// Created by 徐浩闻 on 2024/1/26.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.length()==0) return 0;
        bool hui = true;
        for(int i = 0, j = s.length()-1; i <=j; i++, j--) {
            if (s[i]==s[j]) continue;
            else {
                hui = false;
                break;
            }
        }
        if (hui) return 1;
        else return 2;
    }
};
int main() {


}